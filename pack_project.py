"""
pack_project.py

Merges your modular C++ files into the single source VEXcode IQ expects and
writes it into project.iqcpp (the only file this script modifies).

Run from the yolkic folder:  python pack_project.py
"""
import json
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).parent
TARGET = ROOT / "project.iqcpp"

# Add modules back one at a time once the basic test works.
# Headers go in dependency order; main.cpp always goes last.
HEADERS = ["config.h", "capsule.h"]
SOURCES = ["config.cpp","capsule.cpp", "main.cpp"]
# HEADERS = ["config.h", "cracker.h", "feeder.h"]
# SOURCES = ["config.cpp", "cracker.cpp", "feeder.cpp", "main.cpp"]

VEX_INCLUDE = re.compile(r'^\s*#include\s+"vex\.h"\s*$', re.M)
LOCAL_INCLUDE = re.compile(r'^\s*#include\s+"[^"]+"\s*$', re.M)  # runs after vex.h is removed
PRAGMA_ONCE = re.compile(r'^\s*#pragma\s+once\s*$', re.M)
USING_VEX = re.compile(r'^\s*using\s+namespace\s+vex\s*;\s*$', re.M)
BRAIN_DEF = re.compile(r'^\s*(extern\s+)?brain\s+Brain\s*;\s*$', re.M)  # the IDE owns Brain


def clean(text: str) -> str:
    text = VEX_INCLUDE.sub("", text)
    text = LOCAL_INCLUDE.sub("", text)
    text = PRAGMA_ONCE.sub("", text)
    text = USING_VEX.sub("", text)
    text = BRAIN_DEF.sub("", text)
    return text.strip()


def read(path: Path) -> str:
    if not path.exists():
        sys.exit(f"Missing file: {path}")
    return path.read_text(encoding="utf-8")


def build_code() -> str:
    parts = []
    for name in HEADERS:
        parts.append(f"// ---- {name} ----\n" + clean(read(ROOT / "include" / name)))
        print(f"  Added header: include/{name}")
    for name in SOURCES:
        parts.append(f"// ---- {name} ----\n" + clean(read(ROOT / "src" / name)))
        print(f"  Added source: src/{name}")
    body = "\n\n".join(parts) + "\n"
    # VEXcode's generated setup calls vexcodeInit() at the top of main()
    if "vexcodeInit" not in body:
        body = re.sub(r'(int\s+main\s*\(\s*\)\s*\{)', r'\1\n    vexcodeInit();', body, count=1)
    return body


def main():
    if not TARGET.exists():
        sys.exit("project.iqcpp not found. Create a blank project in VEXcode IQ and save it here first.")

    code = build_code()

    backup = TARGET.with_suffix(".iqcpp.bak")
    if not backup.exists():  # keep the original default file, never overwrite the backup
        shutil.copy(TARGET, backup)

    data = json.loads(read(TARGET))

    # Find the field holding the program text; fall back to the usual name.
    key = next(
        (k for k, v in data.items() if isinstance(v, str) and "#include" in v),
        None,
    )
    if key is None:
        key = "textContent"
        print(f"No existing code field found, using '{key}'. Fields in file: {list(data.keys())}")

    # Keep VEXcode's generated setup (everything up to the end of its robot-config region)
    # and replace only what comes after it with your packed code.
    END_MARKER = "#pragma endregion VEXcode Generated Robot Configuration"
    original = data.get(key, "")
    idx = original.find(END_MARKER)
    if idx == -1:
        print("Could not find VEXcode's generated setup region in project.iqcpp, so nothing was written.")
        print("Fields in file:", list(data.keys()))
        print("Start of the code field:\n", original[:400])
        print("\nReplace project.iqcpp with a fresh blank project saved from VEXcode IQ, then run again.")
        sys.exit(1)
    prefix = original[: idx + len(END_MARKER)]
    data[key] = prefix + "\n\nusing namespace vex;\n\n" + code
    TARGET.write_text(json.dumps(data, separators=(",", ":")), encoding="utf-8")
    print(f"Packed {len(SOURCES)} sources into project.iqcpp (field: '{key}')")


if __name__ == "__main__":
    main()
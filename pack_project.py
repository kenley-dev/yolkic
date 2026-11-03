import os
import zipfile
import json

# Configuration of file paths
OUTPUT_IQCPP = "project.v5rproj.iqcpp"
INCLUDE_DIR = "include"
SRC_DIR = "src"

def pack_project():
    print("📦 Packing modular C++ files into VEX IQ container...")
    
    # VEX IQ projects use a zip structure underneath
    with zipfile.ZipFile(OUTPUT_IQCPP, 'w', zipfile.ZIP_DEFLATED) as zipf:
        
        # Walk through include folder
        if os.path.exists(INCLUDE_DIR):
            for root, _, files in os.walk(INCLUDE_DIR):
                for file in files:
                    file_path = os.path.join(root, file)
                    arcname = os.path.relpath(file_path, ".")
                    zipf.write(file_path, arcname)
                    print(f"  Added header: {arcname}")

        # Walk through src folder
        if os.path.exists(SRC_DIR):
            for root, _, files in os.walk(SRC_DIR):
                for file in files:
                    file_path = os.path.join(root, file)
                    arcname = os.path.relpath(file_path, ".")
                    zipf.write(file_path, arcname)
                    print(f"  Added source: {arcname}")

        # Include the project file if it exists
        if os.path.exists("project.v5rproj"):
            zipf.write("project.v5rproj", "project.v5rproj")
            print("  Added: project.v5rproj")

    print(f"✅ Successfully updated {OUTPUT_IQCPP}! Ready to open in VEX IQ IDE.")

if __name__ == "__main__":
    pack_project()
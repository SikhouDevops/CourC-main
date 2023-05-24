import subprocess

class TerraformManager:
    
    def replace_string(self, old_string, new_string, file):
        command = f"sed -i 's/{old_string}/{new_string}/g' {file}"
        subprocess.run(command, shell=True)

    def run_terraform(self, command):
        subprocess.run(f"terraform {command}", shell=True)

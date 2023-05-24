from file_manager import FileManager
from csv_manager import CSVManager
from terraform_manager import TerraformManager

class Main:
    def __init__(self):
        self.var1 = "var1"
        # ... Plus de variables comme var2, var3, etc.

    def run(self):
        file_manager = FileManager()
        csv_manager = CSVManager()
        terraform_manager = TerraformManager()

        # Suppression des fichiers
        file_manager.remove_file('/path/to/ProgC.tf')
        file_manager.remove_file('/path/to/terraform.tfvars')
        file_manager.remove_file('/path/to/variable.tf')

        # Copie des fichiers
        file_manager.copy_file('/path/to/save/Ec2.tf', '/path/to/Ec2.tf')
        file_manager.copy_file('/path/to/save/terraform.tfvars', '/path/to/terraform.tfvars')
        file_manager.copy_file('/path/to/save/variable.tf', '/path/to/variable.tf')

        # Lecture du fichier CSV et application des commandes Terraform
        for instancename, description, sggroup, owner in csv_manager.read_csv('/path/to/Terraform.csv'):
            terraform_manager.replace_string("TestSikhou", instancename, 'terraform.tfvars')
            terraform_manager.replace_string("TestSikhou", instancename, 'variable.tf')
            terraform_manager.replace_string("TestSikhou", instancename, 'Ec2.tf')
            terraform_manager.replace_string("Input", description, 'Ec2.tf')
            terraform_manager.replace_string("Sikhou-sg", sggroup, 'Ec2.tf')
            terraform_manager.replace_string("azure", owner, 'Ec2.tf')

            file_manager.remove_file('Ec2.tf')

            terraform_manager.run_terraform('init')
            terraform_manager.run_terraform('plan')
            terraform_manager.run_terraform('apply -auto-approve')

            file_manager.copy_file('/path/to/ProgC.tf', '/path/to/ProgC.tf')


if __name__ == "__main__":
    main = Main()
    main.run()

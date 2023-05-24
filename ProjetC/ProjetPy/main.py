from file_manager import FileManager
from csv_manager import CSVManager
from terraform_manager import TerraformManager

class Main:

    def run(self):
        file_manager = FileManager()
        csv_manager = CSVManager()
        terraform_manager = TerraformManager()

        # Suppression des fichiers
        file_manager.remove_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/ProgC.tf')
        file_manager.remove_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/terraform.tfvars')
        file_manager.remove_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/variable.tf')

        # Copie des fichiers
        file_manager.copy_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Save/Ec2.tf', '/c/Users/j24781/Documents/Github/CourC-main/ProjetC')
        file_manager.copy_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Save/terraform.tfvars', '/c/Users/j24781/Documents/Github/CourC-main/ProjetC')
        file_manager.copy_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Save/variable.tf', '/c/Users/j24781/Documents/Github/CourC-main/ProjetC')

        # Lecture du fichier CSV et application des commandes Terraform
        for instancename, description, sggroup, owner in csv_manager.read_csv('/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Terraform.csv'):
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

            file_manager.copy_file('/c/Users/j24781/Documents/Github/CourC-main/ProjetC.tf', '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/SaveProgC.tf')


if __name__ == "__main__":
    main = Main()
    main.run()

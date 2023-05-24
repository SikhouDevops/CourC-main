echo "Suppression du fichier ProgC.tf"
rm '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/ProgC.tf'

echo "Suppression du fichier terraform.tfvars"
rm '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/terraform.tfvars'

echo "Suppression du fichier variable.tf"
rm '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/variable.tf'

echo "Copie de la template Ec2.tf"
cp '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Save/Ec2.tf' '/c/Users/j24781/Documents/Github/CourC-main/ProjetC'

echo "Copie de la template terraform.tfvars"
cp '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Save/terraform.tfvars' '/c/Users/j24781/Documents/Github/CourC-main/ProjetC'

echo "Copie de la template variable.tf"
cp '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/Save/variable.tf' '/c/Users/j24781/Documents/Github/CourC-main/ProjetC'

sed 1d "Terraform.csv" | while IFS=';' read -r instancename description sggroup owner; do
    line="$instancename $description $sggroup"
    
    AC=$(echo $instancename)
    DES=$(echo $description)
    SG=$(echo $sggroup)
    OWN=$(echo $owner)

    echo "$AC"
    echo "$DES"
    echo "$SG"
    echo "$OWN"


    echo "Traitement des fichiers de configuration Terraform"
    echo "Modification du fichier Terraform.tfvars"
    sed -i "s/TestSikhou/$AC/g" terraform.tfvars

    echo "Modification du fichier variable.tf"
    sed -i "s/TestSikhou/$AC/g" variable.tf

    echo "Création du fichier $AC.tf"
    sed -e "s/""TestSikhou""/$AC/g" -e "s/.TestSikhou./$AC/g" -e "s/""Input""/$DES/g" -e "s/""Sikhou-sg""/$SG/g" -e "s/azure/$OWN/g" <EC2.tf >$AC.tf
    
    echo "Fin de la modification des fichiers"
    
    echo "Suppression du fichier EC2 template"
    rm Ec2.tf
    
    echo "Lancement Terraform Init"
    terraform init
    
    echo "Lancement Terraform Plan"
    terraform plan
    
    echo "Lancement Terraform Apply"
    terraform apply -auto-approve

    echo "Instance ec2-$AC Deployed"

    echo "Sauvegarde du fichier $AC.tf"
    cp '/c/Users/j24781/Documents/Github/CourC-main/ProjetC/ProgC.tf' '/c/Users/j24781/Documents/Github/CourC-main/ProjetC'

done

echo "Ce n'est pas fini"
echo "Allons sur AWS :D"
#xdg-open https://us-east-1.console.aws.amazon.com/ec2/v2/home?region=us-east-1#AMICatalog:


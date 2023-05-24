provider "aws" {
    region     = "us-east-1"
    access_key = var.access_key
    secret_key = var.secret_key
}

data "aws_ami" "app_ami" {
    most_recent = true
    owners      = ["amazon"]

    filter {
    name   = "name"
    values = ["amzn2-ami-hvm*"]
    }
}

resource "aws_security_group" "allow_http_https" {
    name        = "SGProgA"
    description = "Entrant"
    vpc_id      = aws_vpc.prog_C_vpc.id

    ingress {
        description = "TLS from VPC"
        from_port   = 443
        to_port     = 443
        protocol    = "tcp"
        cidr_blocks = ["0.0.0.0/0"]
    }

    ingress {
        description = "http from VPC"
        from_port   = 80
        to_port     = 80
        protocol    = "tcp"
        cidr_blocks = ["0.0.0.0/0"]
    }
}


#resource "aws_eip" "lb" {
#    instance = aws_instance.TestProgA.id
#    vpc      = true
#}

resource "aws_vpc" "prog_C_vpc" {
    cidr_block = var.vpc_cidr_block

    tags = {
    Name = var.vpc_name
    }
}

resource "aws_subnet" "prog_C_subnet" {
    vpc_id     = aws_vpc.prog_C_vpc.id
    cidr_block = var.subnet_cidr_block
}

resource "aws_instance" "TestProgA" {
    ami           = data.aws_ami.app_ami.id
    instance_type = var.instancetype
    key_name      = "devops-sikhou"
    tags          = var.aws_common_tag
    subnet_id     = aws_subnet.prog_C_subnet.id
    vpc_security_group_ids = [aws_security_group.allow_http_https.id]
    root_block_device {
        delete_on_termination = true
  }
}

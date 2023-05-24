variable "access_key" {
  description = "AWS access key"
}

variable "secret_key" {
  description = "AWS secret key"
}

variable "vpc_name" {
  description = "Name for the VPC"
  default     = "ProgCVPC"
}

variable "vpc_cidr_block" {
  description = "CIDR block for the VPC"
  default     = "172.31.0.0/16"
}

variable "subnet_cidr_block" {
  description = "CIDR block for the subnet"
  default     = "172.31.10.0/24"
}

variable "instancetype" {
  type        = string
  description = "set aws instance type"
  default     = "t2.micro"
}

variable "aws_common_tag" {
  type        = map
  description = "set aws tag"
  default = {
    Name = "ec2-TestProgA"
  }
}

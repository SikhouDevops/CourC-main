
access_key = "AKIA6D2D55AN6U3GN4XE"
secret_key = "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"

vpc_name   = "ProgCVPC"
vpc_cidr_block    = "172.31.0.0/16"
subnet_cidr_block = "172.31.10.0/24"
instancetype      = "t2.micro"

aws_common_tag = {
    Name = "ec2-TestProgA"
}

import csv

class CSVManager:

    def read_csv(self, path):
        with open(path, newline='') as csvfile:
            csvreader = csv.reader(csvfile, delimiter=';')
            next(csvreader)  # Skip the header row
            return [row for row in csvreader]

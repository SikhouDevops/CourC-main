import os
import shutil

    def remove_file(self, path):
        if os.path.isfile(path):
            os.remove(path)

    def copy_file(self, source, destination):
        shutil.copy(source, destination)

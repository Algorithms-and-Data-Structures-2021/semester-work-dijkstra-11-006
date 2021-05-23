import csv
import os
from random import randint


MAXINT = 1000  # max integer value


class Creator:
    @staticmethod
    def create_data():
        os.chdir(os.path.abspath(os.curdir).replace("cmake-build-debug", ""))
        os.chdir(os.path.abspath(os.curdir).replace("benchmark", ""))
        os.chdir("dataset")

        try:
            os.mkdir("data")
        except Exception as e:
            pass
        os.chdir("data")

        try:
            os.mkdir("database")
        except Exception as e:
            pass
        os.chdir("database")

        folders1 = ['insert']
        folders2 = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10']
        amount = [5, 10, 25, 50, 100, 250, 500, 1000, 1500, 2500]
        for a in folders1:

            try:
                os.mkdir(a)
            except Exception:
                pass
            os.chdir(a)

            for b in folders2:
                try:
                    os.mkdir(b)
                except Exception:
                    continue
                os.chdir(b)

                for i in amount:
                    file_name = "Random_" + str(i) + "x" + str(i) + ".csv"
                    with open(file_name, "w") as file:
                        dataset = csv.writer(file)
                        n = 0
                        for j in range(i):
                            row = []
                            flag = True
                            for k in range(i):
                                if k == n and flag:
                                    row.append(0)
                                    flag = False
                                    n += 1
                                else:
                                    row.append(randint(1, MAXINT))

                            dataset.writerow(row)

                os.chdir('..')
            os.chdir('..')

        print('Done =)')


if __name__ == "__main__":
    Creator.create_data()

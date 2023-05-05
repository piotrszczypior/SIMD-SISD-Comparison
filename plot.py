import sys
import os
import pandas as pd
import matplotlib.pyplot as plt


def plot(directory, files):
    sisd_file, simd_file = (files[0], files[1]) \
        if files[0].split("_")[1].startswith("sisd") \
        else (files[1], files[0])

    df_sisd = pd.read_csv(directory + "\\" + sisd_file, header=None, names=['num_elements', 'time'], delimiter=';')
    df_simd = pd.read_csv(directory + "\\" + simd_file, header=None, names=['num_elements', 'time'], delimiter=';')

    fig, ax = plt.subplots()
    ax.plot(df_sisd['num_elements'], df_sisd['time'], marker='o', label="sisd")
    ax.plot(df_simd['num_elements'], df_simd['time'], marker='o', label="simd")

    ax.set_xlabel('Number of Elements')
    ax.set_ylabel('Time (microseconds)')
    plt.title('Time vs. Number of Elements - ' + files[0].split("_")[0])
    ax.legend()
    plt.show()


def get_csv_files(directory: str):
    if not os.path.exists(directory):
        print(f"Directory '{directory}' does not exist")
        return []
    return [f for f in os.listdir(directory) if f.endswith('.csv')]


def create_graphs(files: list, directory: str):
    if len([f for f in files if f.startswith("add")]) > 0:
        plot(directory, [f for f in files if f.startswith("add")])


directory = sys.argv[1]
files = get_csv_files(directory)
print(files)


create_graphs(files, directory)

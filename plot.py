import sys
import os
import pandas as pd
import matplotlib.pyplot as plt


def plot(directory, files):
    sisd_file, simd_file = (files[0], files[1]) \
        if files[0].split("_")[1].startswith("sisd") \
        else (files[1], files[0])

    df_sisd = pd.read_csv(directory + "/" + sisd_file, header=None, names=['num_elements', 'time'], delimiter=';')
    df_simd = pd.read_csv(directory + "/" + simd_file, header=None, names=['num_elements', 'time'], delimiter=';')

    fig, ax = plt.subplots()
    ax.plot(df_sisd['num_elements'], df_sisd['time'], marker='o', label="sisd")
    ax.plot(df_simd['num_elements'], df_simd['time'], marker='o', label="simd")

    ax.set_xlabel('Number of Elements')
    ax.set_ylabel('Time (nanoseconds)')
    plt.title('Time vs. Number of Elements - ' + files[0].split("_")[0])
    ax.legend()
    plt.show()
    fig.savefig('graphs/' + files[0].split('_')[0], bbox_inches='tight')


def plot_single(directory, file):
    label = file.split('.')[0]
    df = pd.read_csv(directory + "/" + file, header=None, names=['num_elements', 'time'], delimiter=';')

    plt.plot(df['num_elements'], df['time'], marker='o', label=label)
    plt.title('Time vs. Number of Elements - ' + file.split("_")[0])
    plt.legend()
    plt.xlabel('Number of elements')
    plt.ylabel('Time (nanoseconds)')
    fig = plt.gcf()
    plt.show()
    fig.savefig('graphs/' + file.split('.')[0], bbox_inches='tight')


def get_csv_files(directory: str):
    if not os.path.exists(directory):
        print(f"Directory '{directory}' does not exist")
        return []
    return [f for f in os.listdir(directory) if f.endswith('.csv')]


def create_graphs(files: list, directory: str):
    for name in ['add', 'subtract', 'multiply', 'divide']:
        matching_files = [f for f in files if f.split('_')[0] == name]
        print(name)
        print(matching_files)
    
        if len(matching_files) == 1:
            plot_single(directory, matching_files[0])
        elif len(matching_files) == 2:
            plot(directory, matching_files)


directory = sys.argv[1]
files = get_csv_files(directory)
print(files)


create_graphs(files, directory)


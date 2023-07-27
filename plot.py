import matplotlib.pyplot as plt

# Data for each algorithm (6 pairs of (x, y) for each algorithm)
algo_data = {
    'Selection Sort': [(10000, 0.196), (30000, 1.772), (50000, 4.937), (100000, 19.77), (300000, 178.022), (500000, 497.279), ], 
    'Insertion Sort': [(10000, 0.101), (30000, 0.91), (50000, 2.515), (100000, 10.064), (300000, 90.827), (500000, 519.966), ], 
    'Bubble Sort': [(10000, 0.377), (30000, 3.487), (50000, 9.729), (100000, 39.09), (300000, 354.322), (500000, 990.373), ], 
    'Heap Sort': [(10000, 0), (30000, 0.001), (50000, 0.002), (100000, 0.002), (300000, 0.007), (500000, 0.012), ], 
    'Merge Sort': [(10000, 0.003), (30000, 0.009), (50000, 0.014), (100000, 0.03), (300000, 0.095), (500000, 0.16), ], 
    'Quick Sort': [(10000, 0.001), (30000, 0.003), (50000, 0.006), (100000, 0.012), (300000, 0.039), (500000, 0.072), ], 
    'Radix Sort': [(10000, 0.001), (30000, 0.002), (50000, 0.004), (100000, 0.008), (300000, 0.025), (500000, 0.044), ], 
    'Shaker Sort': [(10000, 0.316), (30000, 2.857), (50000, 7.927), (100000, 31.868), (300000, 284.702), (500000, 788.898), ], 
    'Shell Sort': [(10000, 0.002), (30000, 0.007), (50000, 0.013), (100000, 0.027), (300000, 0.093), (500000, 0.163), ], 
    'Counting Sort': [(10000, 0.001), (30000, 0), (50000, 0.001), (100000, 0.002), (300000, 0.004), (500000, 0.008), ], 
    'Flash Sort': [(10000, 0.107), (30000, 0.905), (50000, 2.525), (100000, 10.107), (300000, 90.824), (500000, 252.744), ], 
}

line_colors = ['#1f77b4', '#2ca02c', '#d62728', '#17becf', '#e377c2', '#ff7f0e', '#000000', '#ff9900', '#9467bd', '#8c564b', '#17becf']
algorithm_names = [
    'Selection Sort', 'Insertion Sort', 'Bubble Sort', 'Heap Sort', 'Merge Sort',
    'Quick Sort', 'Radix Sort', 'Shaker Sort', 'Shell Sort', 'Counting Sort', 'Flash Sort'
]

# Create a new figure
plt.figure()

# Plot each algorithm's data
for i in range(11):
    algo = algorithm_names[i]
    data = algo_data[algo]
    x_vals, y_vals = zip(*data)
    plt.plot(x_vals, y_vals, marker='.', label=algo, color=line_colors[i])

# Set labels and title
plt.xlabel('Data Size')
plt.ylabel('Runtime in seconds')
plt.title('Randomized Data')

# Add a legend
plt.legend()
# loc = "center left", bbox_to_anchor=(1.25, 1)

# Display full numbers on the y-axis
# plt.ticklabel_format(style='plain', axis='y')

# Show the plot
plt.show()
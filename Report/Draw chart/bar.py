import matplotlib.pyplot as plt

# Data
algo_name = [
    #'Selection Sort', 'Insertion Sort', 'Bubble Sort', 'Shaker Sort',
    'Flash Sort', 'Heap Sort', 'Merge Sort', 'Quick Sort', 'Radix Sort', 'Shell Sort', 'Counting Sort',
]

algo_comp = {
'10000': (#100010001,50161284,99982610,74954971,
          91964,90567,477685,28556,140056,644754,50001),
'30000': (#900030001,451465952,899920770,674204245,
          275348,272127,1573123,85421,510070,2393886,150001),
'50000': (#2500050001,1247365945,2500044598,1858466431,
          479459,454027,2737108,142126,850070,4518930,232768),
'100000': (#10000100001,4980798873,10000044540,7481114091,
           927670,907024,5774300,279996,1700070,9909637,432769),
'300000': (#90000300001,45000239306,90000109468,67661560019,
           2620281,2721547,18736120,790961,5100070,35828079,1232769),
'500000': (#250000500001,125138809978,249999852780,187319619319,
           4355464,4534916,32287452,1290541,8500070,64289495,2032769),
}

# Set up the figure and axis
fig, ax = plt.subplots(figsize=(12*2, 6*2))

# Define colors for bars
colors = plt.cm.tab20.colors

# Plot each algorithm's data for each set
bar_width = 0.1
x_positions = range(len(algo_name))

scale_size = 1.2
for i, (set_size, comp_data) in enumerate(algo_comp.items()):
    y_pos_adjusted = [x / scale_size for x in comp_data]
    x_pos_adjusted = [pos + bar_width * i for pos in x_positions]
    ax.bar(x_pos_adjusted, y_pos_adjusted, width=bar_width, label=f'Data Size: {set_size}', color=colors[i])

# Set labels and title
# ax.set_xlabel('Algorithms')
# ax.set_ylabel('Number of Comparisons')
# ax.set_title('Randomized Data')
ax.set_xticks([pos + 2.5 * bar_width for pos in x_positions])
ax.set_xticklabels(algo_name, rotation=45, ha='right')

# Add a legend
#ax.legend()

# Display full numbers on the y-axis
ax.ticklabel_format(style='plain', axis='y')

# Show the plot
#plt.tight_layout()
plt.show()
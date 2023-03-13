import os
import csv

# open a CSV file for writing
with open('output.csv', 'w', newline='') as csvfile:
    fieldnames = ['NUM', 'L1_DCM', 'L2_TCM', 'L3_TCM']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    # write the header row
    writer.writeheader()

    # loop through all values between 1 and 550
    for num in range(1, 551):
        # initialize variables for summing the results
        l1_sum = 0
        l2_sum = 0
        l3_sum = 0

        # call the matrix.o executable 10 times and sum the results
        for i in range(10):
            result = os.popen(f"./matrix.o {num}").read().strip()
            result_list = [int(x) for x in result.split(',')]
            num_echo = result_list[0] # the first value is the echoed NUM
            l1_sum += result_list[1]
            l2_sum += result_list[2]
            l3_sum += result_list[3]

        # calculate the averages
        l1_avg = l1_sum / 10
        l2_avg = l2_sum / 10
        l3_avg = l3_sum / 10

        # write a row to the CSV file with the NUM and the average results
        writer.writerow({'NUM': num_echo, 'L1_DCM': l1_avg, 'L2_TCM': l2_avg, 'L3_TCM': l3_avg})

        # print a message indicating the current NUM value being processed
        print(f"Processed NUM {num}")

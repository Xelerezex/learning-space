import pandas as pd

# Read file
crimes_table = pd.read_csv('./Files/Crimes.csv', parse_dates=["Date"])

# Leaves in dataframe data with only 2015 year
group_by_year = crimes_table[
    pd.to_datetime(crimes_table['Date']).dt.year == 2015]

# Grop by Crime type, and count amount of time crimes happens
group_by_crime = group_by_year.groupby(
    ['Primary Type'], as_index=False)['Date'].count().rename(columns={'Date': 'Quantity'})

# Print only one string with max count of crimes
print(group_by_crime.loc[
    group_by_crime['Quantity'] == max(group_by_crime['Quantity'])])


# from collections import Counter as c

# with open('Crimes.csv') as f:
#     data = csv.reader(f)
#     print(c(row[5] for row in data if '2015' in row[2]))

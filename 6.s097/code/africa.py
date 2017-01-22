from utils import *

def parse(k, v):
    return base_parse(k, v)

def clean(items):
    return items

data_crime = parse_csv_data('../data/africa_stats.csv', parse, clean, 1000)

print_dict(data_crime[0])

data_pop = parse_csv_data('../data/africa_pop.csv', parse, clean)

print_dict(data_pop[0])

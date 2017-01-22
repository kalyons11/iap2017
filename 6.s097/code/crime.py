from utils import *

def parse(k, v):
    if k == 'COMPNOS':
        return str(v)
    if k == 'Location':
        v = v[1:-1]
        index = v.index('///')
        x = float(v[:index])
        y = float(v[index + 3:])
        return { 'lat' : x, 'long' : y }
    return base_parse(k, v)

def clean(items):
    out = []
    for k, v in items:
        if (k == 'X' and v == '') or (k == 'Y' and v == ''):
            return None
        else:
            out.append((k, v))
    return out

data = parse_csv_data('../data/crime_data.csv', parse, clean, 1000)
    

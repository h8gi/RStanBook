using Stan, DataFrames, StatPlots
# set backends
plotly()
data = readtable("./input/data-salary.txt")
scatter(data, :X, :Y)

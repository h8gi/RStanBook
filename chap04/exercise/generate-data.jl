using Distributions, StatPlots, DataFrames
N1 = 30
N2 = 20
Y1 = rand(Normal(0, 5), N1)
Y2 = rand(Normal(1, 4), N2)

# ex1
data1 = DataFrame(group=ones(Y1), Y=Y1)
data2 = DataFrame(group=ones(Y2)+1, Y=Y2)
boxplot(data1, :group,:Y)
boxplot!(data2, :group,:Y)

# ex2

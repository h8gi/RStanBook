using Distributions, StatPlots, DataFrames, Stan
cd("/Users/yagi/Projects/RStanBook/chap04/exercise")
plotly()
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
# ex3: ./exercise3.stan
stanmodel1 = Stanmodel(name="ex3", model=readstring("exercise3.stan"))
data = [Dict("N1" => N1, "N2" => N2, "Y1" => Y1, "Y2" => Y2)]
res1 = stan(stanmodel1, data)
describe(res1)

# ex4, Prob[mu1 < mu2]
mu1sim = res1.value[:,findfirst(res1.names, "mu1"),:] |> vec
mu2sim = res1.value[:,findfirst(res1.names, "mu2"),:] |> vec
ex4prob = mean(mu1sim .< mu2sim)

# ex5, sigma1, sigma2
stanmodel2 = Stanmodel(name="ex5", model=readstring("exercise5.stan"))
res2 = stan(stanmodel2, data)
mu1sim2 = res2.value[:,findfirst(res1.names, "mu1"),:] |> vec
mu2sim2 = res2.value[:,findfirst(res1.names, "mu2"),:] |> vec
ex5prob = mean(mu1sim2 .< mu2sim2)

using Distributions, StatPlots, DataFrames, Stan
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

# ex4
mu1sim = res1.value[:,findfirst(res1.names, "mu1"),:] |> vec
mu2sim = res1.value[:,findfirst(res1.names, "mu2"),:] |> vec
ex4prob = count(x->x, mu1sim .< mu2sim) / length(mu1sim)


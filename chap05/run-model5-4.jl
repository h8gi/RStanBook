using Stan, DataFrames, Gadfly
ProjDir = dirname(@__FILE__)
cd(ProjDir)

d = readtable("input/data-attendance-2.txt")
data = [Dict("N" => nrow(d),
             "A" => d[:A],
             "Score" => d[:Score]/200,
             "M" => d[:M],
             "Y" => d[:Y])]
model5_4 = Stanmodel(model=readstring("model/model5-4.stan"))
fit = stan(model5_4, data)

p = plot(fit)
draw(p, filename="summary5-4", fmt=:svg)

fit[:, "lp__", :].value |> vec |> length



using Stan, DataFrames, Gadfly
ProjDir = dirname(@__FILE__)
cd(ProjDir)
# cd("/Users/yagi/Projects/RStanBook/chap05")


# read data
d = readtable("input/data-attendance-1.txt")
# plot data
p = plot(d, x=:A, y=:Score, Geom.boxplot, Geom.point);
p = plot(d, x=:A, y=:Y, Geom.boxplot, Geom.point);
# img = SVG("attendance.svg", 6inch, 4inch)
# draw(img, p)



# read model file
model5_3 = Stanmodel(name="hello", model=readstring("model/model5-3.stan"))
data = [Dict("N" => nrow(d),
             "A" => d[:A],
             "Score" => d[:Score]/200,
             "Y" => d[:Y])]

fit = stan(model5_3, data)

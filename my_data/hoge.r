data <- read.csv("year.csv", sep = ",", header = F)

png()
plot(data, type = "l", xlab = "year", ylab = "char count")
dev.off()

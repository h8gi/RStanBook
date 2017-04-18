model {
  for (n in 1:N) {
	Y[n] ~ normal(b / (a-X[n]), sigma);
  }
}

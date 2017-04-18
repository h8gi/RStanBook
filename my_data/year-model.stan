model {
  for (n in 1:N) {
	Y[n] ~ normal(a + b*X[n], sigma);
  }
}

library(ggplot2)

datos <- read.table("BIG O.txt", header = FALSE)
colnames(datos) <- c("x", "y")

grafico <- ggplot(datos, aes(x = x, y = y)) +
  geom_point() +
  geom_path() +
  labs(x = "# Daots", y = "Tiempo", title = "Gráfico BIG O")

pdf("graficoR.pdf")
print(grafico)
dev.off()

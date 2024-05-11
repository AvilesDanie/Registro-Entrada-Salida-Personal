datos = load('BIG O.txt');

x = datos(:, 1);
y = datos(:, 2);

figure;
scatter(x, y, 'o', 'DisplayName', 'Puntos');
hold on;
plot(x, y, '-r', 'DisplayName', 'Recta que conecta los puntos');
hold off;

xlabel('# Datos');
ylabel('Tiempo');
title('Gráfico BIG O');

saveas(gcf, 'graficoMathlab.pdf');

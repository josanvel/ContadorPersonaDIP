<?php
require_once('./clases/graficos.php');
$ObjGraficos = new graficos($_POST['fecha_inicial'],$_POST['fecha_final']);

if($_POST['tipo'] == 'Lineas') {
	$ObjGraficos->graficar_lineas();
}

if($_POST['tipo'] == 'Barras') {
	$ObjGraficos->graficar_barras();
}

if($_POST['tipo'] == 'Pastel') {
	$ObjGraficos->graficar_pastel();
}
?>
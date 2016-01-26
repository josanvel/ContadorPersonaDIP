<?php
include ("jpgraph/src/jpgraph.php"); 
include ("jpgraph/src/jpgraph_line.php"); 
include ("jpgraph/src/jpgraph_bar.php");

mysql_connect("localhost","root","mysql");
mysql_select_db("db_prueba");

$sql = "SELECT p.Estado, COUNT(1) AS Contador FROM Persons p GROUP BY p.Estado;";
$res = mysql_query($sql);

while ( $row = mysql_fetch_array($res)) {
	$datos[] = $row["Contador"];
	$labels[] = $row["Estado"];
}

// Creamos el grafico
//$datos=array(6,5,8,6);
//$labels=array("Melissa","Jose","Maria","Luis");


// Some data 
$ydata = array(11.5,3,8,12,5,1,9,13,5,7); 

// Create the graph. These two calls are always required 
$graph = new Graph(450,400,"auto");	
$graph->SetScale("textint"); 
$graph->img->SetAntiAliasing(); 
$graph->xgrid->Show(); 

// Create the linear plot 
/*
$lineplot=new LinePlot($ydata); 
$lineplot->SetColor("black"); 
$lineplot->SetWeight(2); 
$lineplot->SetLegend("Horas"); 
*/

// Setup margin and titles 
$graph->img->SetMargin(40,20,20,40); 
$graph->title->Set("Ejemplo Bases de Datos"); 
$graph->xaxis->title->Set("Estado"); 
$graph->xaxis->SetTickLabels($labels);
$graph->yaxis->title->Set("Contador"); 
$graph->ygrid->SetFill(true,'#EFEFEF@0.5','#F9BB64@0.5'); 
//$graph->SetShadow(); 

$barplot1 = new BarPlot($datos);

$barplot1->SetFillGradient("#BE81F7", "#E3CEF6", GRAD_HOR);

$barplot1->SetWidth(30);

// Add the plot to the graph 
$graph->Add($barplot1); 

// Display the graph 
$graph->Stroke();

//$graph->Stroke("IMG.PNG");

?>
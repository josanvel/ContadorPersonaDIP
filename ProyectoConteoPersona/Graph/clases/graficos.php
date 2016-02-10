<?php
require_once ('./jpgraph/src/jpgraph.php');
require_once ('./jpgraph/src/jpgraph_line.php');
require_once ('./jpgraph/src/jpgraph_bar.php');
require_once ('./jpgraph/src/jpgraph_pie.php');
require_once ('./jpgraph/src/jpgraph_pie3d.php');

include_once 'config/conexion.php';

class Graficos {
	
	var $fecha_inicial;
	var $fecha_final;
	var $conexion;

	public function __construct($fecha_inicial, $fecha_final){
		$db = new Conect_MySql();
		$this->conexion = mysql_connect("localhost","root","mysql");
		mysql_select_db("db_prueba", $this->conexion);

		$this->fecha_inicial = $fecha_inicial;
		$this->fecha_final = $fecha_final;
	}

	public function graficar_lineas_Entra() {
		$sql1 = "call PRGetGraficaDiasEntra('$this->fecha_inicial','$this->fecha_final');";
		$res1 = mysql_query($sql1,$this->conexion);
		while ( $row = mysql_fetch_array($res1)) {
			$datos1[] = $row["ContadorMes"];
		}

		$arrlength = count($datos1);
		$nodatos = 0;
		for($x = 0; $x < $arrlength; $x++) {
		    if ($datos1[$x] == 0) {
		    	$nodatos = $nodatos + 1;
		    }
		}

		if( $nodatos == 12 )
		{
			echo 'No existe datos a mostrarse.';
		}else{

			$labels=array("Ene","Feb","Mar","Abr","May","Jun","Jul","Agos","Sep", "Oct","Nov","Dic");
			
			$graph = new Graph(1200,800,'auto');
			$graph->SetScale("textlin");

			$p1 = new LinePlot($datos1);
			$graph->Add($p1);

			$graph->SetMargin(50,30,60,50);
			$graph->title->Set("Cantidad de personas que Entran por Mes");
			//$graph->SetBox(false);
			$graph->xaxis->title->Set("MES");
			//$graph->xaxis->SetTickLabels($labels);
			$graph->yaxis->title->Set("CANTIDAD PERSONAS");

			$graph->title->SetFont(FF_FONT1,FS_BOLD);
			$graph->yaxis->title->SetFont(FF_FONT1,FS_BOLD);
			$graph->xaxis->title->SetFont(FF_FONT1,FS_BOLD);

			$p1->SetColor("blue"); 
			$p1->SetWeight(2);

			$graph->yaxis->SetColor("#FF69B4");
			$graph->yaxis->SetWeight(4);
			$graph->xaxis->SetColor("#5B5C60");
			$graph->xaxis->SetWeight(4);

			$graph->SetShadow();
			$p1->mark->SetType(MARK_FILLEDCIRCLE,'',1.0);
			$p1->mark->SetColor('#66CDAA');
			$p1->mark->SetFillColor('#66CDAA');
			$p1->SetCenter();

			$graph->legend->SetFrameWeight(1);

			$graph->xgrid->Show();
			$graph->xgrid->SetLineStyle("solid");
			$graph->xgrid->SetColor('#E3E3E3');
			
			$graph->legend->SetColor('#4E4E4E','#00A78A');
			$graph->legend->SetMarkAbsSize(8);

			//$p1->value->Show();
			$p1->SetColor("blue");
			$p1->SetLegend('ENTRA');

			$graph->Stroke();
		}
	}

	public function graficar_lineas_Sale() {

		$sql1 = "call PRGetGraficaDiasSale('$this->fecha_inicial','$this->fecha_final');";
		$res1 = mysql_query($sql1,$this->conexion);

		while ( $row = mysql_fetch_array($res1)) {
			$datos1[] = $row["ContadorMes"];
		}

		$arrlength = count($datos1);
		$nodatos = 0;
		for($x = 0; $x < $arrlength; $x++) {
		    if ($datos1[$x] == 0) {
		    	$nodatos = $nodatos + 1;
		    }
		}

		if( $nodatos == 12 )
		{
			echo 'No existe datos a mostrarse.';
		}else{

			$labels=array("Ene","Feb","Mar","Abr","May","Jun","Jul","Agos","Sep", "Oct","Nov","Dic");
			
			$graph = new Graph(1200,800,'auto');
			$graph->SetScale("textlin");

			$p1 = new LinePlot($datos1);
			$graph->Add($p1);

			$graph->SetMargin(50,30,60,50);
			$graph->title->Set("Cantidad de personas que Salen por Mes");
			//$graph->SetBox(false);
			$graph->xaxis->title->Set("MES");
			//$graph->xaxis->SetTickLabels($labels);
			$graph->yaxis->title->Set("CANTIDAD PERSONAS");

			$graph->title->SetFont(FF_FONT1,FS_BOLD);
			$graph->yaxis->title->SetFont(FF_FONT1,FS_BOLD);
			$graph->xaxis->title->SetFont(FF_FONT1,FS_BOLD);

			$p1->SetColor("blue"); 
			$p1->SetWeight(2);

			$graph->yaxis->SetColor("#66CDAA");
			$graph->yaxis->SetWeight(4);
			$graph->xaxis->SetColor("#5B5C60");
			$graph->xaxis->SetWeight(4);

			$graph->SetShadow();
			$p1->mark->SetType(MARK_UTRIANGLE,'',1.0);
			$p1->mark->SetColor('#66CDAA');
			$p1->mark->SetFillColor('#66CDAA');
			$p1->SetCenter();

			$graph->legend->SetFrameWeight(1);

			$graph->xgrid->Show();
			$graph->xgrid->SetLineStyle("solid");
			$graph->xgrid->SetColor('#E3E3E3');

			$graph->legend->SetColor('#4E4E4E','#00A78A');
			$graph->legend->SetMarkAbsSize(8);
			
			//$p1->value->Show();
			$p1->SetColor("blue");
			$p1->SetLegend('SALE');		
			
			$graph->Stroke();
		}
	}

	public function graficar_barras() {

		//Consulta de prueba
		$sql ="call PRGetGraficaDias('$this->fecha_inicial','$this->fecha_final');";

		$res = mysql_query($sql);
		while ( $row = mysql_fetch_array($res)) {
			$datos[] = $row["Contador"];
			$labels[] = $row["Estado"];
		}
		if( empty( $datos ) )
		{
			echo 'No existe datos a mostrarse.';
		}else{

			// Create the graph. These two calls are always required 
			$graph = new Graph(1000,700,"auto");	
			// Setup title
			$graph->title->Set("Cantidad de Personas que Entran - Salen");
			$graph->title->SetFont(FF_ARIAL,FS_BOLD,22);
			$graph->title->SetMargin(20);
			$graph->SetScale("textint"); 
			$graph->img->SetAntiAliasing(); 
			$graph->xgrid->Show();
			// Setup margin and titles 
			$graph->img->SetMargin(200,100,100,40); 
			//$graph->title->Set($_POST['tipo']); 
			$graph->xaxis->title->Set("Estado"); 
			$graph->xaxis->SetTickLabels($labels);
			$graph->yaxis->title->Set("Cantidad de Personas"); 
			$graph->ygrid->SetFill(true,'#EFEFEF','#FCDDB2'); 
			//$graph->SetShadow(); 
			$barplot1 = new BarPlot($datos);
			//$barplot1->SetFillColor("#FFCC00", "#E3CEF6");
			$barplot1->SetWidth(30);
			// Add the plot to the graph 
			$graph->Add($barplot1); 
			//$barplot1->value->SetColor('black','darkred');
			// Display the graph 
			$graph->Stroke();
		}
	}
	
	public function graficar_pastel() {

		$sql ="call PRGetGraficaDias('$this->fecha_inicial','$this->fecha_final');";
		$res = mysql_query($sql);
		while ( $row = mysql_fetch_array($res)) {
			$datos[] = $row["Contador"];
			$labels[] = $row["Estado"];
		}

		if( empty( $datos ) )
		{
			echo 'No existe datos a mostrarse.';
		}else{

			// A new graph
			$graph = new PieGraph(1000,800,'auto');
			$graph->SetFrame(false);
			$graph->img->SetAntiAliasing(); 

			// Setup title
			$graph->title->Set("Porcentaje de Personas que Entran - Salen");
			$graph->title->SetFont(FF_ARIAL,FS_BOLD,22);
			$graph->title->SetMargin(20);

			// The pie plot
			$p1 = new PiePlotC($datos);
			$p1->SetSliceColors(array('hotpink','aquamarine3'));

			// Move center of pie to the left to make better room
			// for the legend
			$p1->SetSize(0.3);
			 
			// Set color for mid circle
			$p1->SetMidColor('white');
			$p1->SetCenter(0.5,0.4);
			$p1->value->SetFont(FF_ARIAL,FS_BOLD,20);
			$p1->value->SetColor('white');
			$p1->value->Show();	
			$p1->SetLabelType(PIE_VALUE_PER);
			$lbl = array("%.1f%%","%.1f%%");
			$p1->SetLabels($lbl);
			$p1->ExplodeAll(10);
			// Legends
			$p1->SetLegends(array("ENTRA","SALE"));
			$graph->legend->SetFont(FF_ARIAL,FS_BOLD,15);
			$graph->legend->SetPos(0.5,0.4,'center','bottom');
			$graph->legend->SetColumns(2);
			 
			$graph->Add($p1);
			$graph->Stroke();
		}
	}
}
?>
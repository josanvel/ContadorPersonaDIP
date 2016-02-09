<?php
require_once ('./jpgraph/src/jpgraph.php');
require_once ('./jpgraph/src/jpgraph_line.php');
require_once ('./jpgraph/src/jpgraph_bar.php');
require_once ('./jpgraph/src/jpgraph_pie.php');
require_once ('./jpgraph/src/jpgraph_pie3d.php');

class Graficos {
	
	var $fecha_inicial;
	var $fecha_final;
	var $conexion;

	public function __construct($fecha_inicial, $fecha_final){
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

		$labels=array("Ene","Feb","Mar","Abr","May","Jun","Jul","Agos","Sep", "Oct","Nov","Dic");
		
		$graph = new Graph(1200,800,'auto');
		$graph->SetScale("textlin");
		$graph->SetMargin(50,30,30,50);
		$graph->title->Set("Graficos");
		$graph->SetBox(false);
		$graph->xaxis->title->Set("MES");
		$graph->xaxis->SetTickLabels($labels);
		$graph->yaxis->title->Set("CANTIDAD PERSONAS");

		$graph->xgrid->Show();
		$graph->xgrid->SetLineStyle("solid");
		$graph->xgrid->SetColor('#E3E3E3');
		
		$p1 = new LinePlot($datos1);
		$graph->Add($p1);
		$p1->value->Show();
		$p1->SetColor("#6495ED");
		$p1->SetLegend('ENTRA');

		$p1->mark->SetType(MARK_FILLEDCIRCLE,'',1.0);
		$p1->mark->SetColor('#55bbdd');
		$p1->mark->SetFillColor('#55bbdd');
		$p1->SetCenter();
		
		$graph->legend->SetFrameWeight(1);

		$graph->legend->SetColor('#4E4E4E','#00A78A');
		$graph->legend->SetMarkAbsSize(8);
		
		$graph->title->SetFont(FF_FONT1,FS_BOLD);
		$graph->yaxis->title->SetFont(FF_FONT1,FS_BOLD);
		$graph->xaxis->title->SetFont(FF_FONT1,FS_BOLD);
		
		$graph->Stroke();
	}

	public function graficar_lineas_Sale() {

		$sql1 = "call PRGetGraficaDiasSale('$this->fecha_inicial','$this->fecha_final');";
		$res1 = mysql_query($sql1,$this->conexion);

		while ( $row = mysql_fetch_array($res1)) {
			$datos1[] = $row["ContadorMes"];
		}

		$labels=array("Ene","Feb","Mar","Abr","May","Jun","Jul","Agos","Sep", "Oct","Nov","Dic");
		
		$graph = new Graph(1200,800,'auto');
		$graph->SetScale("textlin");
		$graph->SetMargin(50,30,30,50);
		$graph->title->Set("Graficos");
		$graph->SetBox(false);
		$graph->xaxis->title->Set("MES");
		$graph->xaxis->SetTickLabels($labels);
		$graph->yaxis->title->Set("CANTIDAD PERSONAS");

		$graph->xgrid->Show();
		$graph->xgrid->SetLineStyle("solid");
		$graph->xgrid->SetColor('#E3E3E3');
		
		$p1 = new LinePlot($datos1);
		$graph->Add($p1);
		$p1->value->Show();
		$p1->SetColor("#FF69B4");
		$p1->SetLegend('SALE');

		$p1->mark->SetType(MARK_UTRIANGLE,'',1.0);
		$p1->mark->SetColor('#FF69B4');
		$p1->mark->SetFillColor('#FF69B4');
		$p1->SetCenter();
		
		$graph->legend->SetFrameWeight(1);

		$graph->legend->SetColor('#4E4E4E','#00A78A');
		$graph->legend->SetMarkAbsSize(8);
		
		$graph->title->SetFont(FF_FONT1,FS_BOLD);
		$graph->yaxis->title->SetFont(FF_FONT1,FS_BOLD);
		$graph->xaxis->title->SetFont(FF_FONT1,FS_BOLD);
		
		$graph->Stroke();
	}

	public function graficar_barras() {

		//Consulta de prueba
		$sql ="call PRGetGraficaDias('$this->fecha_inicial','$this->fecha_final');";

		$res = mysql_query($sql);
		while ( $row = mysql_fetch_array($res)) {
			$datos[] = $row["Contador"];
			$labels[] = $row["Estado"];
		}

		// Create the graph. These two calls are always required 
		$graph = new Graph(1000,700,"auto");	
		$graph->SetScale("textint"); 
		$graph->img->SetAntiAliasing(); 
		$graph->xgrid->Show();
		// Setup margin and titles 
		$graph->img->SetMargin(350,100,100,40); 
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
	
	public function graficar_pastel() {

		$sql ="call PRGetGraficaDias('$this->fecha_inicial','$this->fecha_final');";

		$res = mysql_query($sql);
		while ( $row = mysql_fetch_array($res)) {
			$datos[] = $row["Contador"];
			$labels[] = $row["Estado"];
		}

		// A new graph
		$graph = new PieGraph(1000,800);
		$graph->img->SetAntiAliasing(); 
		// The pie plot
		$p1 = new PiePlotC($datos);
		$p1->SetSliceColors(array('hotpink','aquamarine3','lightblue','gray','darkolivegreen2','turquoise3',
								  'wheat1','lightsalmon','khaki1','orange','cadetblue3','salmon1'));
		 
		// Move center of pie to the left to make better room
		// for the legend
		$p1->SetSize(0.3);
		 
		// Set color for mid circle
		$p1->SetMidColor('white');
		$p1->SetCenter(0.5,0.4);
		$p1->value->Show();
		$p1->value->SetFont(FF_ARIAL,FS_NORMAL,8);
		$p1->ExplodeAll(10);
		 
		// Legends
		$p1->SetLegends(array("ENTRA","SALE"));
		$graph->legend->SetPos(0.9,0.9,'center','bottom');
		$graph->legend->SetColumns(6);
		 
		$graph->Add($p1);
		$graph->Stroke();
	}
}
?>
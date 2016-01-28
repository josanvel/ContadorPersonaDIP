<?php
require_once ('./jpgraph/src/jpgraph.php');
require_once ('./jpgraph/src/jpgraph_line.php');
require_once ('./jpgraph/src/jpgraph_bar.php');
require_once ('./jpgraph/src/jpgraph_pie.php');
require_once ('./jpgraph/src/jpgraph_pie3d.php');

class Graficos {
	
	var $fecha_inicial;
	var $fecha_final;

	public function __construct($fecha_inicial,$fecha_final){
		mysql_connect("localhost","root","");
		mysql_select_db("db_prueba");
		$this->fecha_inicial = $fecha_inicial;
		$this->fecha_final = $fecha_final;
	}
	
	public function graficar_lineas() {

		$ofi1 = array(100,300,250,200,350);
		$ofi2 = array(50,250,300,320,200);
		$labels=array('Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo');
		
		$grafico = new Graph(940,400,'auto');
		$grafico->SetScale("textlin");
		$grafico->SetMargin(50,30,30,50);
		$grafico->title->Set("GASTOS POR MES");
		$grafico->xaxis->title->Set("MES");
		$grafico->xaxis->SetTickLabels($labels);
		$grafico->yaxis->title->Set("GASTOS");
				
		$grafico->xgrid->Show();
		$grafico->xgrid->SetLineStyle("solid");
		$grafico->xgrid->SetColor('#E3E3E3');
		
		$p1 = new LinePlot($ofi1);
		$grafico->Add($p1);
		$p1->value->Show();
		$p1->SetColor("#6495ED");
		$p1->SetLegend('Oficina 1');
		
		$p2 = new LinePlot($ofi2);
		$grafico->Add($p2);
		$p2->value->Show();
		$p2->SetColor("#B22222");
		$p2->SetLegend('Oficina 2');
		
		$grafico->legend->SetFrameWeight(1);
		
		$grafico->title->SetFont(FF_FONT1,FS_BOLD);
		$grafico->yaxis->title->SetFont(FF_FONT1,FS_BOLD);
		$grafico->xaxis->title->SetFont(FF_FONT1,FS_BOLD);
		
		$grafico->Stroke();
	}
	
	public function graficar_barras() {

		//Consulta de prueba
		$sql = "SELECT p.Estado, COUNT(1) AS Contador FROM Persons p GROUP BY p.Estado;";
		$res = mysql_query($sql);

		while ( $row = mysql_fetch_array($res)) {
			$datos[] = $row["Contador"];
			$labels[] = $row["Estado"];
		}


		// Create the graph. These two calls are always required 
		$graph = new Graph(450,400,"auto");	
		$graph->SetScale("textint"); 
		$graph->img->SetAntiAliasing(); 
		$graph->xgrid->Show();
		// Setup margin and titles 
		$graph->img->SetMargin(40,20,20,40); 
		$graph->title->Set($_POST['tipo']); 
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
	}
	
	public function graficar_pastel() {
		$datos = array(100,300);

		$grafico = new PieGraph(940,400,'auto');
		$grafico->SetScale("textlin");
		$grafico->SetMargin(50,30,30,40);
		
		$tema= new VividTheme;
		$grafico->SetTheme($tema);

		$grafico->title->Set("% HOMBRES y MUJERES");

		$p1 = new PiePlot3D($datos);
		$grafico->Add($p1);

		$p1->ShowBorder();
		$p1->SetColor('white');
		$p1->ExplodeSlice(1);
		$grafico->Stroke();
	}
}
?>
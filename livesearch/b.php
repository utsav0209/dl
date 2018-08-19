<?php
header('Access-Control-Allow-Origin: *');
header('Content-type: application/json');
$q=$_GET["q"];
$keyword=strtoupper($q);
$xml=simplexml_load_file("http://tutorial.world.edu/feed/");
foreach ($xml->channel->item as $item) {
    $title = (string) $item->title; // Title Post
    $link   = (string) $item->link; // Url Link
$title2=strtoupper($title);	
$strpos = strpos($title2, $keyword);
if($strpos == TRUE){
echo "<a href='".$link;
echo "'>";
echo $title;
echo "</a><br/>";	
}
}
?>
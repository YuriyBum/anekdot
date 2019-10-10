<?php

ini_set('magic_quotes_gpc', 'on');

$key = htmlspecialchars($_POST["vybor"]);
echo "<p>Ключевое слово: $key</p>";
require_once('wp-config.php');
//Получение случайного числа

$asknumber = $wpdb->get_results(
  $wpdb->prepare(
	'SELECT ID FROM `wp_askDATA` WHERE ASK LIKE "%'.$key.'%"', OBJECT_K
)
        );

$ansnumber = $wpdb->get_results(
   $wpdb->prepare(
        	'SELECT ID FROM `wp_ansDATA` WHERE ANS LIKE "%'.$key.'%"', $meta_key
        )
                );

$askid = mt_rand(0, count($asknumber) - 1);
$ansid = mt_rand(0, count($ansnumber) - 1);

$asket = [];
foreach ( $asknumber as $asked ) :
    $asket[] = $asked->ID;
endforeach;


$ask = $asket[$askid];

$anset = [];
foreach ( $ansnumber as $ansed ) :
    $anset[] = $ansed->ID;
endforeach;

$ans = $anset[$ansid];
//Получение значений
$content = $wpdb->get_var(
  $wpdb->prepare(
	'SELECT ASK FROM `wp_askDATA` WHERE ID ='.$ask, $meta_key
)
        );


        $answer = $wpdb->get_var(
          $wpdb->prepare(
        	'SELECT ANS FROM `wp_ansDATA` WHERE ID ='.$ans, $meta_key
        )
                );

//Вывод анекдота
                echo "<p> $content </p>";
                echo "<p> $answer </p>";

                $askid = 0;
                $ansid = 0;
 ?>

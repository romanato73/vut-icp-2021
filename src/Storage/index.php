<?php

$categories = file_get_contents("structure.json");
$categories = json_decode($categories, true);

function printBlock($block) {
    if (isset($block['composite'])) {
        echo "<h3>Atomic blocks:</h3>";
        foreach ($block['blocks'] as $atomic) {
            printBlock($atomic);
        }
    } else {
        echo "<pre>";
        print_r($block);
        echo "</pre>";
    }
}

foreach($categories as $name => $blocks) {
    echo '<h1>' . $name . '</h1>';
    
    foreach ($blocks as $block) {
        printBlock($block);
    }
}
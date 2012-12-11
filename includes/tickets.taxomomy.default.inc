<?php



function tickets_vocabulary_add() {
  $vocabularies = array (
    array('name' => 'Priority',
      'machine_name' => TICKET_DEFAULT_VOCA_IMPORTANTCE,
    ),
    array('name' => 'State',
      'machine_name' => TICKET_DEFAULT_VOCA_STATE,
    ),
  );
  foreach ($vocabularies as $vocabulary) {
    $exists = taxonomy_vocabulary_machine_name_load($vocabulary['machine_name']);
    if(!$exists) {
      taxonomy_vocabulary_save((object)$vocabulary);
      watchdog('Status', 'Created vocabulary %name', array('%name' => $vocabulary['name']));
    }
    
  }
}

function tickets_taxonomy_term_add() {
  $lists = array(
    TICKET_DEFAULT_VOCA_IMPORTANTCE => array('Highest',
      'High',
      'Normal',
      'Low',
      'Lowest',
    ),
    TICKET_DEFAULT_VOCA_STATE => array('Highest',
      'Open',
      'Waiting for information',
      'Being worked on',
      'Ready for QA',
      'Closed',
    ),
  ); 
  foreach ($lists as $machine_name => $terms) {
    foreach ($terms as $term_name) {
      $vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);
      $term = new stdClass();
      $term->name = $term_name;
      $term->vid = $vocabulary->vid;
      taxonomy_term_save($term);
      watchdog('status', 'Add term %term_name to %machine_name', array('%term_name' => $term_name, '%machine_name' => $machine_name));
    }
  }
}
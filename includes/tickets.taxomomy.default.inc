<?php

define('TICKET_DEFAULT_VOCA_IMPORTANTCE', 'ticket_importance');
define('TICKET_DEFAULT_VOCA_STATE', 'ticket_state');

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
    taxonomy_vocabulary_save((object)$vocabulary);
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
    }
  }
}
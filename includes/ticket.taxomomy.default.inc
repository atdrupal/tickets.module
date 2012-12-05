<?php

function ticket_vocabulary_add() {
  $vocabularies = array (array('name' => 'Ticket Importance',
      'machine_name' => 'ticket_importance',
    ),
    array('name' => 'Ticket State',
      'machine_name' => 'ticket_state',
    ),
  );
  foreach ($vocabularies as $vocabulary) {
    taxonomy_vocabulary_save((object)$vocabulary);
  }
}

function ticket_taxonomy_term_add() {
  $lists = array(
    'ticket_importance' => array('Highest',
      'High',
      'Normal',
      'Low',
      'Lowest',
    ),
    'ticket_state' => array('Highest',
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
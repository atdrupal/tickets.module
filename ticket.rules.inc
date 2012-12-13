<?php

/**
 * Implements hook_rules_action_info().
 */
function ticket_rules_action_info() {
  $actions['ticket_change_state'] = array(
    'label' => t('Ticket change state'),
    'group' => t('Ticket'),
    'parameter' => array(
      'ticket_category' => array(
        'type' => 'ticket_category',
        'label' => t('Ticket category entity'),
      ),
      'fields' => array(
        'type' => 'text',
        'options list' => 'ticket_vocabulary_state_list',
        'label' => t('State'),
        'description' => t('Choose state'),
      ),
    ),
  );
  $actions['ticket_change_importance'] = array(
    'label' => t('Ticket change importance'),
    'group' => t('Ticket category'),
    'parameter' => array(
      'ticket_category' => array(
        'type' => 'ticket_category',
        'label' => t('Ticket category entity'),
      ),
      'fields' => array(
        'type' => 'text',
        'options list' => 'ticket_vocabulary_importance_list',
        'label' => t('State'),
        'description' => t('Choose state'),
      ),
    ),
  );
  return $actions;
}

function ticket_change_state($ticket_category, $term_id) {
  $ticket_category->ticket_category_state[LANGUAGE_NONE][0]['tid'] = $term_id;
  $ticket_category->save($ticket_category);
}

function ticket_change_importance($ticket_category, $term_id) {
  $ticket_category->ticket_category_importance[LANGUAGE_NONE][0]['tid'] = $term_id;
  $ticket_category->save($ticket_category);
}

function ticket_vocabulary_state_list() {
  $vc = taxonomy_vocabulary_machine_name_load(TICKET_DEFAULT_VOCA_STATE);
  $terms = taxonomy_get_tree($vc->vid);
  foreach($terms as $term) {
    $list[$term->tid] = $term->name;
  }
  return $list;
}

function ticket_vocabulary_importance_list() {
  $vc = taxonomy_vocabulary_machine_name_load(TICKET_DEFAULT_VOCA_IMPORTANTCE);
  $terms = taxonomy_get_tree($vc->vid);
  foreach($terms as $term) {
    $list[$term->tid] = $term->name;
  }
  return $list;
}
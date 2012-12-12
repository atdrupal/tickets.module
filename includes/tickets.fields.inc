<?php


//Assigned to
/**
 * Add body field to ticket bundle in entity_type ticket
 * @param type $type
 * @param type $label
 * @return type
 */
function tickets_add_body_field($type, $label = 'Body') {
  // Add or remove the body field, as needed.
  $field_name = 'ticket_body';
  $entity_type = $bundle = 'ticket';
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    $field = array(
      'field_name' => $field_name, 
      'type' => 'text_with_summary', 
      'entity_types' => array($entity_type),
    );
    $field = field_create_field($field);
    watchdog('status', 'Created field %field_name', array('%field_name' => $field_name));
  }
  if (empty($instance)) {
    $instance = array(
      'field_name' => $field_name, 
      'entity_type' => $entity_type, 
      'bundle' => $bundle, 
      'label' => $label, 
      'widget' => array('type' => 'text_textarea_with_summary'), 
      'settings' => array('display_summary' => TRUE), 
      'display' => array(
        'default' => array(
          'label' => 'hidden', 
          'type' => 'text_default',
        ), 
        'teaser' => array(
          'label' => 'hidden', 
          'type' => 'text_summary_or_trimmed',
        ),
      ),
    );
    field_create_instance($instance);
    watchdog('status', 'Add field %field_name to %bundle',  array('%field_name' => $field_name, '%bundle' => $bundle));
  }
  return $instance;
}

/**
 * Add file field to ticket bundle in entity_type ticket
 * @param type $label
 * @return type
 */
function tickets_add_file_field() {
  $field_name = 'ticket_file_upload';
  $entity_type = $bundle = 'ticket';
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    $field = array(
      'field_name' => $field_name, 
      'type' => 'file', 
      'entity_types' => array($entity_type),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    );
    $field = field_create_field($field);
    watchdog('status', 'Created field %field_name', array('%field_name' => $field_name));
  }
  if (empty($instance)) {
    $instance = array(
      'field_name' => $field_name, 
      'entity_type' => $entity_type, 
      'bundle' => $bundle, 
      'label' => 'File attachments', 
      'widget' => array('type' => 'file_generic'), 
      'settings' => array('progress_indicator' => 'bar'), 
    );
    field_create_instance($instance);
    watchdog('status', 'Add field %field_name to %bundle',  array('%field_name' => $field_name, '%bundle' => $bundle));
  }
  return $instance;
}


function tickets_category_add_term_reference() {
  
  $entity_type = $bundle = 'ticket_category';
  $field_names = array(
    TICKET_DEFAULT_VOCA_IMPORTANTCE => array(
      'label' => 'Importance',
      'name' => 'ticket_category_importance',
    ),
    TICKET_DEFAULT_VOCA_STATE => array(
      'label' => 'State',
      'name' => 'ticket_category_state',
    )
  );
  foreach ($field_names as $voca_machine => $field) {
    
    $field_info = field_info_field($field['name']);
    $instance = field_info_instance($entity_type, $field['name'], $bundle);
    if (empty($field_info)) {
      $field_info = array(
        'field_name' => $field['name'],
        'type' => 'taxonomy_term_reference',
//        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
        'settings' => array(
          'allowed_values' => array(
            array(
              'vocabulary' => $voca_machine,
              'parent' => 0,
            ),
          ),
        ),
      );
      field_create_field($field_info);
      watchdog('status', 'Created field %field_name', array('%field_name' => $field['name']));
    }
    
    if (empty($instance)) {
      $instance = array(
        'field_name' => $field['name'],
        'entity_type' => $entity_type,
        'label' => $field['label'],
        'bundle' => $bundle,
        'description' => '',
        'widget' => array(
          'type' => 'options_select',
          'weight' => -4,
        ),
        'display' => array(
          'default' => array(
            'type' => 'taxonomy_term_reference_link',
            'weight' => 10,
          ),
          'teaser' => array(
            'type' => 'taxonomy_term_reference_link',
            'weight' => 10,
          ),
        ),
      );
      field_create_instance($instance);
      watchdog('status', 'Add field %field_name to %bundle',  array('%field_name' => $field['name'], '%bundle' => $bundle));
    }
  }
}


function tickets_add_entity_reference() {
  $entity_type = $bundle = 'ticket';
  $field_names = array(
    'ticket_entity_reference_user' => array(
      'label' => 'Assigned to',
      'name' => 'ticket_entity_reference_user',
      'target_type' => 'user',
      'widget' => array(
          'type' => 'options_select',
          'weight' => -4,
        ),
    ),
    'ticket_entity_reference_category' => array(
      'label' => 'Category',
      'name' => 'ticket_entity_reference_category',
      'target_type' => 'ticket_category',
      'widget' => array(
        'weight' => -4,
        'type' => 'inline_entity_form',
        'module' => 'inline_entity_form',
        'settings' => array(
          'allow_existing'  => 1,
          'match_operator' => 'CONTAINS',
        ),
      )
    )
  );
  foreach ($field_names as $field_name => $field) {
    $field_info = field_info_field($field_name);
    $instance = field_info_instance($entity_type, $field_name, $bundle);
    if (empty($field_info)) {
      $field_info = array(
        'field_name' => $field_name,
        'type' => 'entityreference',
        'settings' => array('target_type' => $field['target_type']),
      );
      field_create_field($field_info);
      watchdog('status', 'Created field %field_name', array('%field_name' => $field['name']));
    }
    if (empty($instance)) {
      $instance = array(
        'field_name' => $field_name,
        'entity_type' => $entity_type,
        'label' => $field['label'],
        'bundle' => $bundle,
        'description' => '',
        'widget' => $field['widget'],
      );
      field_create_instance($instance);
      watchdog('status', 'Add field %field_name to %bundle',  array('%field_name' => $field['name'], '%bundle' => $bundle));
    }
  }
}
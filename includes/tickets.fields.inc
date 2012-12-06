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
  $field = field_info_field($field_name);//kpr($field);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (empty($field)) {
    $field = array(
      'field_name' => $field_name, 
      'type' => 'text_with_summary', 
      'entity_types' => array($entity_type),
    );
    $field = field_create_field($field);
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
    $instance = field_create_instance($instance);
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
    $instance = field_create_instance($instance);
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
  foreach ($field_names as $voca_machine => $field_name) {
    $field = field_info_field($field_name['name']);
    $instance = field_info_instance($entity_type, $field_name['name'], $bundle);
    if (empty($field)) {
      $field = array(
        'field_name' => $field_name['name'],
        'type' => 'taxonomy_term_reference',
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
        'settings' => array(
          'allowed_values' => array(
            array(
              'vocabulary' => $voca_machine,
              'parent' => 0,
            ),
          ),
        ),
      );
      field_create_field($field);
    }
    if (empty($instance)) {
      $instance = array(
        'field_name' => $field_name['name'],
        'entity_type' => $entity_type,
        'label' => $field_name['label'],
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
    }
  }
  return $instance;
}


function tickets_add_entity_reference() {
  $entity_type = $bundle = 'ticket';
  $field_names = array(
    'ticket_entity_reference_user' => array(
      'label' => 'Assigned to',
      'name' => 'ticket_entity_reference_user',
      'target_type' => 'user'
    ),
    'ticket_entity_reference_category' => array(
      'label' => 'Category',
      'name' => 'ticket_entity_reference_category',
      'target_type' => 'ticket_category'
    )
  );
  foreach ($field_names as $field_name => $field_info) {
    $field = field_info_field($field_name);
    $instance = field_info_instance($entity_type, $field_name, $bundle);
    if (empty($field)) {
      $field = array(
        'field_name' => $field_name,
        'type' => 'entityreference',
        'settings' => array('target_type' => $field_info['target_type']),
      );
      field_create_field($field);
    }
    if (empty($instance)) {
      $instance = array(
        'field_name' => $field_name,
        'entity_type' => $entity_type,
        'label' => $field_info['label'],
        'bundle' => $bundle,
        'description' => '',
        'widget' => array(
          'type' => 'options_select',
          'weight' => -4,
        ),
      );
      field_create_instance($instance);
    }
  }
//  return $instance;
}
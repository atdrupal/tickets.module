<?php


/**
 * Create douple field
 * 1. field ticket_category_importance
 * 2. field ticket_category_state
 * @param type $entity_type
 * @param type $bundle
 */
function tickets_create_field_ref_term($entity_type, $bundle) {
  $field_infos = array(
    TICKET_DEFAULT_VOCA_IMPORTANTCE => array(
      'label' => 'Importance',
      'field_name' => 'ticket_category_importance',
    ),
    TICKET_DEFAULT_VOCA_STATE => array(
      'label' => 'State',
      'field_name' => 'ticket_category_state',
    )
  );
  foreach ($field_infos as $vc_machine => $field_info) {
    $field = field_info_field($field_info['field_name']);
    if (empty($field)) {
      $field = array(
        'field_name' => $field_info['field_name'],
        'type' => 'taxonomy_term_reference',
        'settings' => array('allowed_values' => array(array('vocabulary' => $vc_machine,'parent' => 0))),
      );
      $field =  field_create_field($field);
      watchdog('status', 'Created field %field_name', array('%field_name' => $field['field_name']));
    }
    $widget = array('type' => 'options_select','weight' => -4);
    $display = array(
      'default' => array('type' => 'taxonomy_term_reference_link','weight' => 10),
      'teaser' => array('type' => 'taxonomy_term_reference_link','weight' => 10),
    );
    tickets_create_instance($field, $entity_type, $bundle, $field_info['label'], $widget, array(), $display);
  }
}


/**
 * Create a field 
 * - name: ticket_entity_reference_user
 * - label: Assigned to
 * @param type $entity_type
 * @param type $bundle
 */
function tickets_create_field_ref_user($entity_type, $bundle) {
  $field = field_info_field('ticket_entity_reference_user');
  if (empty($field)) {
    $field = array(
      'field_name' => 'ticket_entity_reference_user',
      'type' => 'entityreference',
      'settings' => array('target_type' => 'user'),
    );
    $field = field_create_field($field);
    watchdog('status', 'Created field %field_name', array('%field_name' => $field['field_name']));
  }
  $widget = array(
    'type' => 'options_select',
    'weight' => -4,
  );
  tickets_create_instance($field, $entity_type, $bundle, 'Assigned to', $widget);
}



/**
 * Create a field 
 * - name: ticket_entity_reference_category
 * - label: Category
 * @param type $entity_type
 * @param type $bundle
 */
function tickets_create_field_ref_category($entity_type, $bundle) {
  $field = field_info_field('ticket_entity_reference_category');
  if (empty($field)) {
    $field = array(
      'field_name' => 'ticket_entity_reference_category',
      'type' => 'entityreference',
      'settings' => array('target_type' => 'ticket_category'),
    );
    $field = field_create_field($field);
    watchdog('status', 'Created field %field_name', array('%field_name' => $field['field_name']));
  }
  $widget = array(
    'weight' => -4,
    'type' => 'inline_entity_form',
    'module' => 'inline_entity_form',
    'settings' => array(
      'allow_existing'  => 1,
      'match_operator' => 'CONTAINS',
    )
  );
  tickets_create_instance($field, $entity_type, $bundle, 'Category', $widget);
}



/**
 * Create a field
 * - name: body
 * - label: Body
 * 
 * @param type $entity_type
 * @param type $bundle
 */
function tickets_create_field_body($entity_type, $bundle) {
  //body field in ticket
  $widget = array('type' => 'text_textarea_with_summary');
  $settings = array('display_summary' => TRUE);
  $display = array(
    'default' => array('label' => 'hidden', 'type' => 'text_default'), 
    'teaser' => array('label' => 'hidden', 'type' => 'text_summary_or_trimmed'),
  );
  $field = field_info_field('field_ticket_body');
  if (empty($field)) {
    $field = array(
      'field_name' => 'ticket_body', 
      'type' => 'text_with_summary', 
      'entity_types' => array('ticket'),
    );
    $field =  field_create_field($field);
    watchdog('status', 'Created field %field_name', array('%field_name' => $field['field_name']));
  }
  tickets_create_instance($field, $entity_type, $bundle, 'Body', $widget, $settings);
}


/**
 * Create a field
 * - name: ticket_file_upload
 * - label: File attachments
 * @param type $entity_type
 * @param type $bundle
 */
function tickets_create_field_file($entity_type, $bundle) {
  //create field
  $field = field_info_field('ticket_file_upload');
  if (empty($field)) {
    $field = array(
      'field_name' => 'ticket_file_upload', 
      'type' => 'file', 
      'entity_types' => array($entity_type),
      'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    );
    $field =  field_create_field($field);
    watchdog('status', 'Created field %field_name', array('%field_name' => $field['field_name']));
  }
  //create an instance
  $widget = array('type' => 'file_generic'); 
  $settings = array('progress_indicator' => 'bar');
  tickets_create_instance($field, $entity_type, $bundle, 'File attachments', $widget, $settings, array());
}

/**
 * Create an instance
 * @param type $field
 * @param type $entity_type
 * @param type $bundle
 * @param type $label
 * @param type $widget
 * @param type $settings
 * @param type $display
 */
function tickets_create_instance($field, $entity_type, $bundle, $label, $widget = array(), $settings = array(), $display = array()) {
  $instance = field_info_instance($entity_type, $field['field_name'], $bundle);
  if (empty($instance)) {
    $instance = array(
      'field_name' => $field['field_name'],
      'entity_type' => $entity_type,
      'label' => $label,
      'bundle' => $bundle,
      'description' => '',
      'widget' => $widget,
      'settings' => $settings,
      'display' => $display,
    );
    field_create_instance($instance);
    watchdog('status', 'Add field %field_name to %bundle',  array('%field_name' => $field['field_name'], '%bundle' => $bundle));
  }
}
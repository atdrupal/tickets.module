<?php
/**
 * @file lgentity.admin.inc
 */

function ticket_form($form, &$form_state, $entity, $op = 'edit', $entity_type) {
  if (!$entity->type) $entity->type = $entity_type;
  
  //kpr($entity_type);exit;
  // Attach fields
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($entity->title) ? $entity->title : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  field_attach_form($entity_type, $entity, $form, $form_state);

  $form['actions']['#weight'] = 100;
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for machine-recommend entity.
 */
function ticket_form_submit($form, &$form_state) {
  $entity = entity_ui_form_submit_build_entity($form, $form_state);
  $entity->save();

//  if (isset($entity->field_ref_lesson[LANGUAGE_NONE][0]['target_id'])) {
//    $form_state['redirect'] = "node/{$entity->field_ref_lesson[LANGUAGE_NONE][0]['target_id']}";
//  }
//  else {
//    $form_state['redirect'] = 'admin/structure/langgo/machine/recommend';
//  }
}
<?php

/**
 * @file
 * Ticket type editing UI.
 */

/**
 * UI controller.
 */
class TicketTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage ticket entity types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the ticket type editing form.
 */
function ticket_type_form($form, &$form_state, $ticket_type, $op = 'edit') {

  if ($op == 'clone') {
    $ticket_type->label .= ' (cloned)';
    $ticket_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $ticket_type->label,
    '#description' => t('The human-readable name of this ticket type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($ticket_type->type) ? $ticket_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $ticket_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'ticket_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this ticket type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save ticket type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$ticket_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete ticket type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('ticket_type_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function ticket_type_form_submit(&$form, &$form_state) {
  $ticket_type = entity_ui_form_submit_build_entity($form, $form_state);
  $ticket_type->save();
  $form_state['redirect'] = 'admin/structure/ticket_types';
}

/**
 * Form API submit callback for the delete button.
 */
function ticket_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/ticket_types/manage/' . $form_state['ticket_type']->type . '/delete';
}
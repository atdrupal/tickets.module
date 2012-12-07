<?php

/**
 * @file
 * Defines the inline entity form controller for Nodes.
 */

class TicketCategoryInlineEntityFormController extends EntityInlineEntityFormController {

  /**
  * Overrides EntityInlineEntityFormController::labels().
   */
  public function labels() {
    $labels = array(
      'singular' => t('node'),
      'plural' => t('nodes'),
    );
    return $labels;
  }

  /**
   * Overrides EntityInlineEntityFormController::entityForm().
   */
  public function entityForm($entity_form, &$form_state) {
    $node = $entity_form['#entity'];
//    kpr(debug_backtrace());exit;
    $extra_fields = field_info_extra_fields('ticket_category', 'ticket_category', 'form');
    if (!isset($node->name)) {
      $node->name = NULL;
    }

    $entity_form['name'] = array(
      '#type' => 'textfield',
      '#title' => 'Name',
      '#required' => TRUE,
      '#default_value' => $node->name,
      '#maxlength' => 255,
      // The label might be missing if the Title module has replaced it.
      '#weight' => !empty($extra_fields['name']) ? $extra_fields['name']['weight'] : -5,
    );
//  kpr($entity_form);
    field_attach_form('ticket_category', $node, $entity_form, $form_state, LANGUAGE_NONE);
//    kpr($entity_form);exit;
    return $entity_form;
  }
  
  
//  /**
//   * Overrides EntityInlineEntityFormController::entityFormSubmit().
//   */
//  public function entityFormSubmit(&$entity_form, &$form_state) {
//    parent::entityFormSubmit($entity_form, $form_state);
////    kpr('callback');exit;
//    node_submit($entity_form['#entity']);
//    $child_form_state = form_state_defaults();
//    $child_form_state['values'] = drupal_array_get_nested_value($form_state['values'], $entity_form['#parents']);
//    foreach (module_implements('node_submit') as $module) {
//      $function = $module . '_node_submit';
//      $function($entity_form['#entity'], $entity_form, $child_form_state);
//    }
//  }

}

<?php

/**
 * @file
 * Ticket editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class TicketUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Tickets',
      'description' => 'Add edit and update tickets.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of tickets.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a ticket',
      'description' => 'Add a new ticket',
      'page callback'  => 'ticket_add_page',
      'access callback'  => 'ticket_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'ticket.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
    
    // Add menu items to add each different type of entity.
    foreach (ticket_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'ticket_form_wrapper',
        'page arguments' => array(ticket_create(array('type' => $type->type))),
        'access callback' => 'ticket_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'ticket.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing ticket entities
    $items[$this->path . '/ticket/' . $wildcard] = array(
      'page callback' => 'ticket_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'ticket_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'ticket.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/ticket/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/ticket/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'ticket_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'ticket_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'ticket.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing tickets
    $items['ticket/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'ticket_page_title',
      'title arguments' => array(1),
      'page callback' => 'ticket_page_view',
      'page arguments' => array(1),
      'access callback' => 'ticket_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add Ticket Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('ticket_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a ticket.
 *
 * @param $ticket
 *   The ticket object being edited by this form.
 *
 * @see ticket_edit_form()
 */
function ticket_form_wrapper($ticket) {
  // Add the breadcrumb for the form's location.
  ticket_set_breadcrumb();
  return drupal_get_form('ticket_edit_form', $ticket);
}


/**
 * Form callback wrapper: delete a ticket.
 *
 * @param $ticket
 *   The ticket object being edited by this form.
 *
 * @see ticket_edit_form()
 */
function ticket_delete_form_wrapper($ticket) {
  // Add the breadcrumb for the form's location.
  //ticket_set_breadcrumb();
  return drupal_get_form('ticket_delete_form', $ticket);
}


/**
 * Form callback: create or edit a ticket.
 *
 * @param $ticket
 *   The ticket object to edit or for a create form an empty ticket object
 *     with only a ticket type defined.
 */
function ticket_edit_form($form, &$form_state, $ticket) {
  // Add the default field elements.
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Ticket Name'),
    '#default_value' => isset($ticket->title) ? $ticket->title : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  

  // Add the field related form elements.
  $form_state['ticket'] = $ticket;
  field_attach_form('ticket', $ticket, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save ticket'),
    '#submit' => $submit + array('ticket_edit_form_submit'),
  );
  
  if (!empty($ticket->title)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete ticket'),
      '#suffix' => l(t('Cancel'), 'admin/content/tickets'),
      '#submit' => $submit + array('ticket_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'ticket_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the ticket form
 */
function ticket_edit_form_validate(&$form, &$form_state) {
  $ticket = $form_state['ticket'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('ticket', $ticket, $form, $form_state);
}


/**
 * Form API submit callback for the ticket form.
 * 
 * @todo remove hard-coded link
 */
function ticket_edit_form_submit(&$form, &$form_state) {
  
  $ticket = entity_ui_controller('ticket')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the ticket and go back to the list of tickets
  
  // Add in created and changed times.
  if ($ticket->is_new = isset($ticket->is_new) ? $ticket->is_new : 0){
    $ticket->created = time();
  }

  $ticket->changed = time();
  
  $ticket->save();
  $form_state['redirect'] = 'admin/content/tickets';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function ticket_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/tickets/ticket/' . $form_state['ticket']->ticket_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a ticket.
 *
 * @param $ticket
 *   The ticket to delete
 *
 * @see confirm_form()
 */
function ticket_delete_form($form, &$form_state, $ticket) {
  $form_state['ticket'] = $ticket;

  $form['#submit'][] = 'ticket_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete ticket %title?', array('%title' => $ticket->title)),
    'admin/content/tickets/ticket',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for ticket_delete_form
 */
function ticket_delete_form_submit($form, &$form_state) {
  $ticket = $form_state['ticket'];

  ticket_delete($ticket);

  drupal_set_message(t('The ticket %title has been deleted.', array('%title' => $ticket->title)));
  watchdog('ticket', 'Deleted ticket %title.', array('%title' => $ticket->title));

  $form_state['redirect'] = 'admin/content/tickets';
}



/**
 * Page to add Ticket Entities.
 *
 * @todo Pass this through a proper theme function
 */
function ticket_add_page() {
  $controller = entity_ui_controller('ticket');
  return $controller->addPage();
}


/**
 * Displays the list of available ticket types for ticket creation.
 *
 * @ingroup themeable
 */
function theme_ticket_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="ticket-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer ticket types')) {
      $output = '<p>' . t('Ticket Entities cannot be added because you have not created any ticket types yet. Go to the <a href="@create-ticket-type">ticket type creation page</a> to add a new ticket type.', array('@create-ticket-type' => url('admin/structure/ticket_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No ticket types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative ticket pages.
 */
function ticket_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Tickets'), 'admin/content/tickets'),
  );

  drupal_set_breadcrumb($breadcrumb);
}




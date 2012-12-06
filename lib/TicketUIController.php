<?php

//admin/structure/tickets/manage
class EntityTicketUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
//    kpr($items);exit;
//    // Overview
//    $items['admin/structure/tickets']
//      = $items['admin/structure/tickets/edit']
//      = $items['admin/structure/tickets'];
//    
//    
//    $items['admin/structure/tickets']['title']
//      = $items['admin/structure/tickets/edit']['title']
//      = t('Ticket');
//
//    // Entity add page
//    $items['ticket/add'] = $items['admin/structure/tickets/add'];
//    unset(
//      $items['admin/structure/tickets/add']['title callback'],
//      $items['admin/structure/tickets/add']['title arguments']
//    );
//    $items['ticket/add']['title'] = 'Create new Ticket';
//
//    $items['admin/structure/tickets/edit']['type'] = MENU_DEFAULT_LOCAL_TASK;

//    unset($items['admin/structure/langgo/machine']);
//    unset($items['admin/structure/langgo/machine/list']);
//    unset($items['admin/structure/langgo/machine/add']);
//
//    unset($items['admin/structure/langgo/machine/manage/%entity_object/clone']);

    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket';
    return parent::overviewTable($conditions);
  }
}










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
    //$wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;
    kpr('run');exit;
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
//    foreach (ticket_get_types() as $type) {
//      $items[$this->path . '/add/' . $type->type] = array(
//        'title' => 'Add ' . $type->label,
//        'page callback' => 'ticket_form_wrapper',
//        'page arguments' => array(ticket_create(array('type' => $type->type))),
//        'access callback' => 'ticket_access',
//        'access arguments' => array('edit', 'edit ' . $type->type),
//        'file' => 'ticket.admin.inc',
//        'file path' => drupal_get_path('module', $this->entityInfo['module'])
//      );
//    }

    // Loading and editing ticket entities
    $items[$this->path . '/' . $wildcard] = array(
      'page callback' => 'ticket_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'ticket_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'ticket.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/' . $wildcard . '/delete'] = array(
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
  
}
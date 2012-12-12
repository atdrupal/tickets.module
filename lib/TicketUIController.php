<?php

class EntityTicketUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    //Define menu callback View mode ticket
    $items['ticket/%ticket'] = array(
      'title callback' => 'tickets_page_title',
      'title arguments' => array(1),
      'page callback' => 'tickets_page_view',
      'page arguments' => array(1),
      'access arguments' => array('access_content'),
      'type' => MENU_CALLBACK,
    );
//    $items['ticket/%ticket/edit'] = array(
//      'title' => 'test',
////      'title callback' => 'tickets_page_title',
////      'title arguments' => array(1),
//      'page callback' => 'ticket_form_wrapper',
//      'page arguments' => array(1),
//      'access callback' => 'user_access',
////      'access arguments' => array('administer tickets'),
//      'access arguments' => array('access content'),
//      'type' => MENU_CALLBACK,
//      'file path' => drupal_get_path('module','tickets'),
//      'file' => 'includes/tickets.admin.inc',
//    );
    
    
//    $items['ticket/%ticket/view'] = array(
//      'title' => 'View',
//      'type' => MENU_DEFAULT_LOCAL_TASK,
//      'weight' => -10,
//    );
//    kpr($items);
//    $items['ticket/%entity_object'] = $items['/ticket/manage/%entity_object'];
//    $items['ticket/%entity_object/%'] = $items['ticket/manage/%entity_object/%'];
//    $items['ticket/%entity_object/edit'] = $items['ticket/manage/%entity_object/edit'];
//    $items['ticket/%entity_object/clone'] = $items['ticket/manage/%entity_object/clone'];
//    $items['ticket/%entity_object/edit']['type'] = MENU_DEFAULT_LOCAL_TASK;
//    $items['ticket/%entity_object/clone']['type'] = MENU_DEFAULT_LOCAL_TASK;
//    unset($items['ticket/manage/%entity_object']);
    unset($items['ticket/manage/%entity_object/edit']);
//    unset($items['ticket/manage/%entity_object/clone']);
//    unset($items['ticket/manage/%entity_object']);
//    unset($items['ticket/manage/%entity_object/%']);
//    kpr($items);exit;
    return $items;
  }

  public function overviewTable($conditions = array()) {
    $conditions['type'] = 'ticket';
    return parent::overviewTable($conditions);
  }
}


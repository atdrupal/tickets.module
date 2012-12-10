<?php

/**
 * Implements hook_views_data()
 */
function tickets_views_data_alter(&$data) { 
//  kpr($data['ticket']);exit;
  $data['ticket']['link_ticket'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the ticket.'),
      'handler' => 'ticket_handler_link_field',
    ),
  );
  $data['ticket']['edit_ticket'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the ticket.'),
      'handler' => 'ticket_handler_edit_link_field',
    ),
  );
  $data['ticket']['delete_ticket'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the ticket.'),
      'handler' => 'ticket_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows tickets/ticket/%ticket_id/op
  $data['ticket']['operations_ticket'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this ticket.'),
      'handler' => 'ticket_handler_ticket_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function ticket_views_default_views() {
  $views = array();
  $view = new view();
  $view->name = 'ticket';
  $view->description = 'Views ticket manage';
  $view->tag = 'default';
  $view->base_table = 'ticket';
  $view->human_name = 'ticket';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tickets Manger';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'ticket_id' => 'ticket_id',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'user' => 'user',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'ticket_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Ticket: Ticket ID */
  $handler->display->display_options['fields']['ticket_id']['id'] = 'ticket_id';
  $handler->display->display_options['fields']['ticket_id']['table'] = 'ticket';
  $handler->display->display_options['fields']['ticket_id']['field'] = 'ticket_id';
  $handler->display->display_options['fields']['ticket_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket_id']['format_plural'] = TRUE;
  /* Field: Ticket: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'ticket';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'ticket/[ticket_id]';
  /* Field: Ticket: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ticket';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Ticket: Delete Link */
  $handler->display->display_options['fields']['delete_ticket']['id'] = 'delete_ticket';
  $handler->display->display_options['fields']['delete_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['delete_ticket']['field'] = 'delete_ticket';
  /* Field: Ticket: Edit Link */
  $handler->display->display_options['fields']['edit_ticket']['id'] = 'edit_ticket';
  $handler->display->display_options['fields']['edit_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['edit_ticket']['field'] = 'edit_ticket';
  /* Field: Ticket: Link */
  $handler->display->display_options['fields']['link_ticket']['id'] = 'link_ticket';
  $handler->display->display_options['fields']['link_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['link_ticket']['field'] = 'link_ticket';
  /* Field: Ticket: Assigned user */
  $handler->display->display_options['fields']['field_assigned_user']['id'] = 'field_assigned_user';
  $handler->display->display_options['fields']['field_assigned_user']['table'] = 'field_data_field_assigned_user';
  $handler->display->display_options['fields']['field_assigned_user']['field'] = 'field_assigned_user';
  $handler->display->display_options['fields']['field_assigned_user']['settings'] = array(
    'link' => 0,
  );
  /* Field: Ticket: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['settings'] = array(
    'link' => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/tickets';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tickets category';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Ticket: Category (field_category) */
  $handler->display->display_options['arguments']['field_category_target_id']['id'] = 'field_category_target_id';
  $handler->display->display_options['arguments']['field_category_target_id']['table'] = 'field_data_field_category';
  $handler->display->display_options['arguments']['field_category_target_id']['field'] = 'field_category_target_id';
  $handler->display->display_options['arguments']['field_category_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_category_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_category_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_category_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_category_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'ticket-category/%';

  $views[] = $view;
  return $views;
}
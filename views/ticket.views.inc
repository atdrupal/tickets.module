<?php

/**
 * Implements hook_views_data()
 */
function ticket_views_data_alter(&$data) { 

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
  // follows ticket/ticket/%ticket_id/op
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
  $view->name = 'ticket_assigned';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ticket';
  $view->human_name = 'Ticket Assigned Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ticket Assigned';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'ticket_category_importance',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = '[ticket_category_importance]';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'ticket_body' => 'ticket_body',
    'ticket_entity_reference_user' => 'ticket_entity_reference_user',
    'nothing_1' => 'nothing_1',
    'delete_ticket' => 'delete_ticket',
    'edit_ticket' => 'edit_ticket',
    'ticket_category_importance' => 'ticket_category_importance',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ticket_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ticket_entity_reference_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_ticket' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_ticket' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ticket_category_importance' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['ticket_entity_reference_category_target_id']['id'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['relationships']['ticket_entity_reference_category_target_id']['table'] = 'field_data_ticket_entity_reference_category';
  $handler->display->display_options['relationships']['ticket_entity_reference_category_target_id']['field'] = 'ticket_entity_reference_category_target_id';
  /* Field: Ticket: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'ticket';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Ticket: Body */
  $handler->display->display_options['fields']['ticket_body']['id'] = 'ticket_body';
  $handler->display->display_options['fields']['ticket_body']['table'] = 'field_data_ticket_body';
  $handler->display->display_options['fields']['ticket_body']['field'] = 'ticket_body';
  $handler->display->display_options['fields']['ticket_body']['label'] = '';
  $handler->display->display_options['fields']['ticket_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket_body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['ticket_body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['ticket_body']['element_label_colon'] = FALSE;
  /* Field: Ticket: Assigned to */
  $handler->display->display_options['fields']['ticket_entity_reference_user']['id'] = 'ticket_entity_reference_user';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['table'] = 'field_data_ticket_entity_reference_user';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['field'] = 'ticket_entity_reference_user';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket_entity_reference_user']['type'] = 'editable';
  $handler->display->display_options['fields']['ticket_entity_reference_user']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'entityreference_label',
    'fallback_settings' => array(
      'link' => 0,
    ),
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="ticket-content">
      <h2 class="title">[title]</h2>
      <div class="body">[ticket_body]</div>
      <div class="assigned "><span>Assigned to:</span>[ticket_entity_reference_user] </div>
      </div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Ticket: Delete Link */
  $handler->display->display_options['fields']['delete_ticket']['id'] = 'delete_ticket';
  $handler->display->display_options['fields']['delete_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['delete_ticket']['field'] = 'delete_ticket';
  $handler->display->display_options['fields']['delete_ticket']['exclude'] = TRUE;
  /* Field: Ticket: Edit Link */
  $handler->display->display_options['fields']['edit_ticket']['id'] = 'edit_ticket';
  $handler->display->display_options['fields']['edit_ticket']['table'] = 'ticket';
  $handler->display->display_options['fields']['edit_ticket']['field'] = 'edit_ticket';
  $handler->display->display_options['fields']['edit_ticket']['exclude'] = TRUE;
  /* Field: Ticket category: Importance */
  $handler->display->display_options['fields']['ticket_category_importance']['id'] = 'ticket_category_importance';
  $handler->display->display_options['fields']['ticket_category_importance']['table'] = 'field_data_ticket_category_importance';
  $handler->display->display_options['fields']['ticket_category_importance']['field'] = 'ticket_category_importance';
  $handler->display->display_options['fields']['ticket_category_importance']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['fields']['ticket_category_importance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ticket_category_importance']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="delete-link">[delete_ticket]</div>
      <div class="edit-link">[edit_ticket]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Ticket */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'ticket';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Sort criterion: Ticket category: Importance (ticket_category_importance) */
  $handler->display->display_options['sorts']['ticket_category_importance_tid']['id'] = 'ticket_category_importance_tid';
  $handler->display->display_options['sorts']['ticket_category_importance_tid']['table'] = 'field_data_ticket_category_importance';
  $handler->display->display_options['sorts']['ticket_category_importance_tid']['field'] = 'ticket_category_importance_tid';
  $handler->display->display_options['sorts']['ticket_category_importance_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'admin/ticket';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Tickets';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/ticket/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'All tickets';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: open */
  $handler = $view->new_display('page', 'open', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tickets open';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Ticket category: State (ticket_category_state) */
  $handler->display->display_options['filters']['ticket_category_state_tid']['id'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['filters']['ticket_category_state_tid']['field'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['filters']['ticket_category_state_tid']['value'] = array(
    0 => '7',
  );
  $handler->display->display_options['filters']['ticket_category_state_tid']['vocabulary'] = 'ticket_state';
  $handler->display->display_options['path'] = 'admin/ticket/open';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'opened';
  $handler->display->display_options['menu']['description'] = 'Tickets open';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: being */
  $handler = $view->new_display('page', 'being', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The tickets being worked on';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Ticket category: State (ticket_category_state) */
  $handler->display->display_options['filters']['ticket_category_state_tid']['id'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['filters']['ticket_category_state_tid']['field'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['filters']['ticket_category_state_tid']['value'] = array(
    0 => '9',
  );
  $handler->display->display_options['filters']['ticket_category_state_tid']['vocabulary'] = 'ticket_state';
  $handler->display->display_options['path'] = 'admin/ticket/being';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'being';
  $handler->display->display_options['menu']['description'] = 'The tickets being worked on';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: highest */
  $handler = $view->new_display('page', 'highest', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The tickets highest';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Ticket category: State (ticket_category_state) */
  $handler->display->display_options['filters']['ticket_category_state_tid']['id'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['filters']['ticket_category_state_tid']['field'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['filters']['ticket_category_state_tid']['value'] = array(
    0 => '6',
  );
  $handler->display->display_options['filters']['ticket_category_state_tid']['vocabulary'] = 'ticket_state';
  $handler->display->display_options['path'] = 'admin/ticket/highest';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Highest';
  $handler->display->display_options['menu']['description'] = 'The tickets highest';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: ready */
  $handler = $view->new_display('page', 'ready', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The tickets ready for QA';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Ticket category: State (ticket_category_state) */
  $handler->display->display_options['filters']['ticket_category_state_tid']['id'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['filters']['ticket_category_state_tid']['field'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['filters']['ticket_category_state_tid']['value'] = array(
    0 => '10',
  );
  $handler->display->display_options['filters']['ticket_category_state_tid']['vocabulary'] = 'ticket_state';
  $handler->display->display_options['path'] = 'admin/ticket/ready';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'ready';
  $handler->display->display_options['menu']['description'] = 'The tickets ready for QA';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: waiting */
  $handler = $view->new_display('page', 'waiting', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The tickets waiting for information';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Ticket category: State (ticket_category_state) */
  $handler->display->display_options['filters']['ticket_category_state_tid']['id'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['filters']['ticket_category_state_tid']['field'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['filters']['ticket_category_state_tid']['value'] = array(
    0 => '8',
  );
  $handler->display->display_options['filters']['ticket_category_state_tid']['vocabulary'] = 'ticket_state';
  $handler->display->display_options['path'] = 'admin/ticket/waiting';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'waiting';
  $handler->display->display_options['menu']['description'] = 'Waiting for information';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: closed */
  $handler = $view->new_display('page', 'closed', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The tickets closed';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Ticket category: State (ticket_category_state) */
  $handler->display->display_options['filters']['ticket_category_state_tid']['id'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['table'] = 'field_data_ticket_category_state';
  $handler->display->display_options['filters']['ticket_category_state_tid']['field'] = 'ticket_category_state_tid';
  $handler->display->display_options['filters']['ticket_category_state_tid']['relationship'] = 'ticket_entity_reference_category_target_id';
  $handler->display->display_options['filters']['ticket_category_state_tid']['value'] = array(
    0 => '11',
  );
  $handler->display->display_options['filters']['ticket_category_state_tid']['vocabulary'] = 'ticket_state';
  $handler->display->display_options['path'] = 'admin/ticket/closed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'closed';
  $handler->display->display_options['menu']['description'] = 'The tickets closed';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;


  $views[] = $view;
  return $views;
}
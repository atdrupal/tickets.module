<?php

/**
 * Access callback
 */
function _ticket_service_resources_access($op, $args) {
  
}
/**
 * Ticket create service callback
 */
function _ticket_service_resources_create($entity_type, $values) {
  kpr($values);exit;
}


/**
 * Ticket update service callback
 */
function _ticket_service_resources_update($entity_type, $entity_id, $values) {

  
}


/**
 * Ticket delete service callback
 */
function _ticket_service_resources_delete($entity_type, $entity_id) {
  kpr($values);exit;
}


/**
 * Ticket index service callback
 */
function _ticket_service_resources_index($entity_type, $fields, $parameters, $page, $pagesize, $sort, $direction) {
  kpr($values);exit;
}


/**
 * Ticket retrieve service callback
 */
function _ticket_service_resources_retrieve($entity_type, $entity_id, $fields) {
  kpr($values);exit;
}
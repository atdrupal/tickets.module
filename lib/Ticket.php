<?php

class TicketEntity extends Entity {
  public $ticket_id;
  public $type;
  public $uid;
  public $created;
  public $changed;

  public function __construct(array $values = array(), $entityType = 'ticket') {
    parent::__construct($values, $entityType);

    if (!$this->created) $this->created = REQUEST_TIME;
    if (!$this->changed) $this->changed = REQUEST_TIME;
    if (!$this->uid) $this->uid = user_is_anonymous() ? 0 : $GLOBALS['user']->uid;
  }
  protected function defaultUri() {
      return array('path' => 'ticket/' . $this->ticket_id);
  }
  
  /**
   * Returns the user owning this ticket.
   */
  public function user() {
    return user_load($this->uid);
  }

}




/**
 * Commerce Product translation handler.
 *
 * This class is registered in commerce_product.module using the translation
 * property the Entity Translation module uses via hook_entity_info().
 *
 * @see commerce_product_entity_info()
 */
class EntityTranslationTicketHandler extends EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity) {
    parent::__construct('ticket', $entity_info, $entity);
  }
}

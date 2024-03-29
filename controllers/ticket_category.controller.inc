<?php

class TicketCategoryEntity extends Entity {
  public $ticket_cid;
  public $type;
  public $uid;
  public $created;
  public $changed;
  public $name;

  public function __construct(array $values = array(), $entityType = 'ticket_category') {
    parent::__construct($values, $entityType);
    $this->type = 'ticket_category';
    if (!$this->created) $this->created = REQUEST_TIME;
    if (!$this->changed) $this->changed = REQUEST_TIME;
    if (!$this->uid) $this->uid = user_is_anonymous() ? 0 : $GLOBALS['user']->uid;
  }
  protected function defaultUri() {
      return array('path' => 'ticket-category/' . $this->ticket_cid);
  }
  
  /**
   * Returns the user owning this ticket category.
   */
  public function user() {
    return user_load($this->uid);
  }
  
}
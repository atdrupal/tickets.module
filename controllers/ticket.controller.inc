<?php

class TicketEntity extends Entity {
  public $ticket_id;
  public $type;
  public $uid;
  public $created;
  public $changed;
  public $title;
  public $language;
  

  public function __construct(array $values = array(), $entityType = 'ticket') {
    parent::__construct($values, $entityType);
    
    $this->language = LANGUAGE_NONE;
    $this->type = 'ticket';
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

